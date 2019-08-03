#include <iostream>
#include <vector>
#define max_int 10001
using namespace std;

int n, m, k, a, b, from[max_int];
bool check[max_int];
vector<int> v[max_int];

void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        
        if(!check[next]){
            from[next] = node;
            dfs(next);
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(k);
    
    for(int i=1; i<=n; i++){
        cout << from[i] << endl;
    }
}
