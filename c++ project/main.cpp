#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;


vector<int> a[1001];
bool check[1001];

void dfs(int node){
    check[node] = true;
    cout << node <<" ";
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        cout << node <<" ";

        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
        
    }
}


int main(){
    
    int n, m, v;
    cin >> n >> m >> v;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=0; i<n; i++){
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(v);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(v);
    cout << endl;
}
