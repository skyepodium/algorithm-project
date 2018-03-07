#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node){

    check[node] = true;
    cout << node <<" ";
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        
        if(check[next] == false){
            check[next] = true;
            dfs(next);
        }
    }
}

void bfs(int start){
    memset(check, false, sizeof(check));
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        cout << node <<" ";
        q.pop();
        
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
    
    int n, m, start;
    cin >> n >> m >> start;
    
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=0; i<n; i++){
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(start);
    cout << endl;
    bfs(start);
    cout << endl;
}
