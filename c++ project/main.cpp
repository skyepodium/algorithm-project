#include <iostream>
#include <vector>

#define  max_int 1001
using namespace std;

int n, m, a, b, cnt = 0;
bool check[max_int];
vector<int> v[max_int];

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            dfs(next);
            
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
        if(check[i] == false){
            dfs(i);
            cnt++;
        }
    }
    
    printf("%d\n", cnt);
}
