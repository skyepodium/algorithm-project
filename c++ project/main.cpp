#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[20001];
bool check[20001];
int color[20001];
bool result = true;

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(color[next] == color[node]){
            result = false;
            break;
        }
        if(check[next] == false){
            dfs(next);
        }
    }
}


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, m;
        cin >> n >> m;

        for(int i=1; i<=n; i++){
            a[i].clear();
            check[i] = 2;
        }
        result = true;
        
        
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for(int i=1; i<=n; i++){
            color[i] = i%2;
        }
        
        for(int i=1; i<=n; i++){
            if(check[i] == 0){
                dfs(i);
            }
        }
        
        
        for(int i=0; i<n; i++){
            cout << color[i] << endl;
        }
        
        if(result){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        
    }
    
}
