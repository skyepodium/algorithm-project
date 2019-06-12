#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max_int 101
using namespace std;

int n, m, a, b;
bool check[max_int];
vector<int> v[max_int];

void dfs (int node) {
    check[node] = true;
    printf("%d", node);
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!check[next]){
            printf("-");
            dfs(next);
        }
    }
}

void bfs (int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        if(check[node]){
            printf("-%d", node);
        }else{
            printf("%d", node);
            check[node] = true;
        }
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    dfs(1);
    printf("\n");
    for(int i=0; i<=n; i++) check[i] = false;
    bfs(1);
    printf("\n");
}
