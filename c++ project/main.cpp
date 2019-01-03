#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_int 1001
using namespace std;


bool check[max_int];
vector<int> v[max_int];

int n, m, start_node, a, b;

void dfs(int node){
    check[node] = true;
    printf("%d ", node);
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int node = q.front();
        printf("%d ", node);
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &start_node);

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(start_node);
    for(int i=0; i<=n; i++) check[i] = false;
    printf("\n");
    bfs(start_node);
}