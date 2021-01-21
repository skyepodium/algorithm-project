#include <iostream>
#include <queue>
#include <vector>

#define max_int 10001
using namespace  std;

int n, m, k, a, b;
bool check[max_int];
vector<int> v[max_int];

void dfs(int node) {
    check[node] = true;
    for(auto next: v[node]) {
        if(!check[next]) {
            dfs(next);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1);
    
    if(check[k]) printf("Yes\n");
    else printf("No\n");
}
