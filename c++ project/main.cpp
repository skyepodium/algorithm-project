#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<int> a[1001];
bool check[1001];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
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
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            bfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
