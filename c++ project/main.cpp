#include <iostream>
#include <vector>

using namespace std;

vector<int> a[101];
bool check[101];

int cnt = 0;

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            check[next] = true;
            cnt++;
            dfs(next);
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
    
    dfs(1);
    
    cout << cnt << endl;
}
