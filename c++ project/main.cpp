#include <iostream>
#include <vector>
#include <queue>
#define max_int 100001
#define max_val 100000000001
using namespace std;

int n, m, a, b, c, p[max_int];
long long int d[max_int];

struct info{
    int cur;
    long long int cost;
};
vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

void dijkstra(){
    priority_queue<info, vector<info>, cmp> pq;
    p[1] = 0;
    d[1] = 0;
    pq.push({1, d[1]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;
        
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            long long int n_cost = next.cost;
            
            if(d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
                p[n_node] = c_node;
                pq.push({n_node, d[n_node]});
            }
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        d[i] = max_val;
    }
}

void go(int c_node){
    if(c_node == 0) return;
    else{
        go(p[c_node]);
        printf("%d ", c_node);
    }
        
}

int main(){
    scanf("%d %d", &n, &m);
   
    init();
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, (long long int)c});
        v[b].push_back({a, (long long int)c});
    }
    
    dijkstra();
    
    if(d[n] != max_val){
        go(n);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}
