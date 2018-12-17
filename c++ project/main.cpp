#include <iostream>
#include <vector>

#define max_int 100001
using namespace std;

int n, a, b;
vector<int> v[max_int];
bool check[max_int];
int parent[max_int];

void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            parent[next] = node;
            dfs(next);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1);
    for(int i=2; i<=n; i++){
        printf("%d\n", parent[i]);
    }
}
