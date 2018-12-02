#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 40001
using namespace std;

int n, m, a, b, c;
bool check[max_int];
int parent[max_int];
int depth[max_int];
int dist[max_int];
int p[max_int][18];
struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];

int lca(int first, int second){
    if(depth[first] < depth[second]){
        swap(first, second);
    }
    
    int log = 1;
    for(log=1; (1<<log) <= depth[first]; log++);
    log--;
    
    for(int i=log; i>=0; i--){
        if(depth[first] - (1<<i) >= depth[second]){
            first = p[first][i];
        }
    }
    
    if(first == second){
        return first;
    }
    else{
        for(int i=log; i>=0; i--){
            if(p[first][i] !=0 && p[first][i] != p[second][i]){
                first = p[first][i];
                second = p[second][i];
            }
        }
        return parent[first];
    }
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
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i].cur;
            int cost = v[node][i].cost;
            
            if(check[next] == false){
                check[next] = true;
                parent[next] = node;
                depth[next] = depth[node] + 1;
                dist[next] = dist[node] + cost;
                q.push(next);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        p[i][0] = parent[i];
    }
    
    for(int j=1; (1<<j) < n; j++){
        for(int i=1; i<=n; i++){
            if(p[i][j-1] != 0){
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }
    
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", dist[a] + dist[b] - 2*dist[lca(a, b)]);
    }
    
    
    
}
