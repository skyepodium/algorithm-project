#include <iostream>
#include <vector>
#define max_int 101
using namespace std;

int t, n, m, a, b, result;
vector<int> v[max_int];
bool check[max_int];

void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!check[next]){
            dfs(next);
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        v[i].clear();
        check[i] = false;
    }
    result = 0;
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);
        
        init();
        
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(int i=1; i<=n; i++){
            if(!check[i]){
                dfs(i);
                result++;
            }
        }
        printf("#%d %d\n", test_case, result);
    }
}
