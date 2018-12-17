#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 100001
using namespace std;

int n;
struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];
bool check[max_int];
int dist[max_int];

void dfs(info node){
    int c_node = node.cur;
    check[c_node] = true;
    
    for(int i=0; i<v[c_node].size(); i++){
        info next = v[c_node][i];
        int n_node = next.cur;
        int n_cost = next.cost;
        
        if(check[n_node] == false){
            dist[n_node] = dist[c_node] + n_cost;
            dfs({n_node, dist[n_node]});
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int node;
        scanf("%d", &node);
        
        while(true){
            int next;
            scanf("%d", &next);
            if(next == -1) break;
            int cost;
            scanf("%d", &cost);
            v[node].push_back({next, cost});
        }
    }
    
    dist[1] = 0;
    dfs({1, dist[1]});
    int max_idx = 1;
    int max_length = 0;
    for(int i=2; i<=n; i++){
        if(dist[i] > max_length){
            max_length = dist[i];
            max_idx = i;
        }
    }
    for(int i=1; i<=n; i++){
        dist[i] = 0;
        check[i] = false;
    }
    dist[max_idx] = 0;
    dfs({max_idx, dist[max_idx]});

    int result = 0;
    for(int i=1; i<=n; i++){
        result = max(result, dist[i]);
    }
    printf("%d\n", result);
    
}
