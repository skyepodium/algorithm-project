#include <iostream>
#include <queue>
#include <vector>

#define max_int 501
#define max_val 2147483647
using namespace std;

int n, m, start_node, end_node, a, b, c;

bool check[max_int][max_int];
int d[max_int];
struct edge{
    int cur;
    int cost;
};

vector<edge> v[max_int];
vector<edge> rv[max_int];
struct cmp{
    bool operator()(const edge &a, const edge &b){
        return a.cost > b.cost;
    }
};


void dijkstra(){
    d[start_node] = 0;
    priority_queue<edge, vector<edge>, cmp> pq;
    pq.push({start_node, d[start_node]});
    
    while(!pq.empty()){
        edge node = pq.top();
        int c_node = node.cur;
        pq.pop();
        
        for(int i=0; i<v[c_node].size(); i++){
            edge next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(check[c_node][n_node] == false && d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
                pq.push({n_node, d[n_node]});
            }
        }
    }
}

void reverse_dijkstra(){
    priority_queue<edge, vector<edge>, cmp> pq;
    pq.push({end_node, d[end_node]});
    
    while(!pq.empty()){
        edge node = pq.top();
        int c_node = node.cur;
        pq.pop();
        
        for(int i=0; i<rv[c_node].size(); i++){
            edge next = rv[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(d[n_node] == d[c_node] - n_cost){
                check[n_node][c_node] = true;
                pq.push({n_node, d[n_node]});
            }
        }
    }
}


int main(){
    while(true){
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) break;
        scanf("%d %d", &start_node, &end_node);
        
        for(int i=0; i<=n-1; i++){
            d[i] = max_val;
            v[i].clear();
            rv[i].clear();
            for(int j=0; j<=n-1; j++){
                check[i][j] = false;
            }
        }
        
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back({b, c});
            rv[b].push_back({a, c});
        }
    
    
        dijkstra();
        reverse_dijkstra();
        for(int i=0; i<=n-1; i++) d[i] = max_val;
        dijkstra();
        if(d[end_node] == max_val) printf("-1\n");
        else printf("%d\n", d[end_node]);
    }
}
