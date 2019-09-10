#include <iostream>
#include <vector>
#define max_int 1001
using namespace std;

int t, n, a, b, result, check[max_int], start_node;
vector<int> v[max_int];

int max(int a, int b){
    return a > b ? a : b;
}

void dfs(int node, int prev){
    check[node] = check[prev] + 1;

    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == -1){
            dfs(next, node);
        }
        else if(next == start_node){
            result = max(result, check[prev] + 1);
        }
    }
}

void clear(){
    check[0] = 0;
    for(int i=1; i<=n; i++){
        check[i] = -1;
    }
}

void init(){
    result = n;
    for(int i=0; i<=n; i++){
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(int i=1; i<=n; i++){
            clear();
            start_node = i;
            dfs(i, 0);     
        }
        
        printf("#%d %d\n", test_case, result);
    }
}
