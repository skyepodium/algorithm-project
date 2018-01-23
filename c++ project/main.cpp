#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1001];
int check[1001];

void dfs(int node){
    
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        for(int i=0; i<=n; i++){
            a[i].clear();
            check[i] = 0;
        }
        
        for(int i=1; i<=n; i++){
            int v;
            cin >> v;
            a[i].push_back(v);
            a[v].push_back(i);
        }

        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(check[i] == false){
                dfs(i);
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
    
    
}
