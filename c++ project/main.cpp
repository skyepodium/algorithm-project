#include <iostream>
#include <vector>
#include <queue>
#define max_val 2147483647
#define max_int 1001
using namespace std;

int t, n, m, start_node, a, b, c, d[max_int], e[max_int], result;

struct info{
    int cur, cost;
};

int max(int a, int b){
    return a > b ? a : b;
}

vector<info> v[max_int], r[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

void dijkstra(){
    priority_queue<info, vector<info>, cmp> pq;
    d[start_node] = 0;
    pq.push({start_node, d[start_node]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;
        
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

void r_dijkstra(){
    priority_queue<info, vector<info>, cmp> pq;
    e[start_node] = 0;
    pq.push({start_node, e[start_node]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;
        
        for(int i=0; i<r[c_node].size(); i++){
            info next = r[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(e[n_node] > e[c_node] + n_cost){
                e[n_node] = e[c_node] + n_cost;
                pq.push({n_node, e[n_node]});
            }
        }
    }
}

void init(){
    result = 0;
    for(int i=0; i<=n; i++){
        d[i] = max_val;
        e[i] = max_val;
        v[i].clear();
        r[i].clear();
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d %d", &n, &m, &start_node);
        
        init();
        
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back({b, c});
            r[b].push_back({a, c});
        }
        
        dijkstra();
        r_dijkstra();
        
        for(int i=1; i<=n; i++){
            result = max(result, d[i] + e[i]);
        }
        
        printf("#%d %d\n", test_case, result);
        
    }
}
