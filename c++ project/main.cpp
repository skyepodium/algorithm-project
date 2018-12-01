#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 50001
using namespace std;

int n, m, a, b, c;
int parent[max_int];
int depth[max_int];
bool check[max_int];
int dist[max_int];

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];

int lca(int first, int second){
    int result = 0;
    if(depth[first] < depth[second]){
        swap(first, second);
    }
    
    while(depth[first] != depth[second]){
        result += dist[first];
        first = parent[first];
    }
    
    while(first != second){
        result += dist[first];
        result += dist[second];
        first = parent[first];
        second = parent[second];
    }
    
    return result;
}


int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    check[1] = true;
    parent[1] = 0;
    depth[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int c_node = q.front();
        q.pop();
        
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            if(check[n_node] == false){
                check[n_node] = true;
                parent[n_node] = c_node;
                depth[n_node] = depth[c_node] + 1;
                dist[n_node] = n_cost;
                q.push(n_node);
            }
        }
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    
    
    
}
