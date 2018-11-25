#include <iostream>
#include <vector>
#include <queue>

#define max_val 2147483647
#define max_int 1001
using namespace std;

int n, m, a, b, c;
struct info{
    int cur;
    int cost;
};

int d[max_int];
int p[max_int];
vector<info> v[max_int];
vector<pair<int, int>> result;
struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int find(int node){
    if(p[node] == node) return node;
    else return p[node] = find(p[node]);
}

void first_dijkstra(){
    d[1] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({1, d[1]});
    
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        int c_node = node.cur;
        
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
                pq.push({n_node, d[n_node]});
            }
        }
    }
}

void second_dijkstra(){
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({1, d[1]});
    
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        int c_node = node.cur;
        
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(d[n_node] == d[c_node] + n_cost){
                if(find(n_node) != find(c_node)){
                    p[find(n_node)] = find(c_node);
                    result.push_back(make_pair(c_node, n_node));
                }
                pq.push({n_node, d[n_node]});
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        d[i] = max_val;
        p[i] = i;
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    first_dijkstra();
    second_dijkstra();
    
    printf("%d\n", (int)result.size());
    for(int i=0; i<(int)result.size(); i++){
        printf("%d %d\n", result[i].first, result[i].second);
    }
    
    
}
