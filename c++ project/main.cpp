#include <iostream>
#include <vector>

#define max_int 50001
using namespace std;

int n, m, a, b;
vector<int> v[max_int];
int l[max_int];
int p[max_int];
bool check[max_int];

void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!check[next]){
            l[next] = l[node] + 1;
            p[next] = node;
            dfs(next);
        }
    }
}

int lca(int first, int second){
    if(l[first] < l[second]){
        swap(first, second);
    }

    while(l[first] != l[second]){
        first = p[first];
    }
    while(first != second){
        first = p[first];
        second = p[second];
    }
    return first;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    l[1] = 1;
    p[1] = 1;
    dfs(1);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }


}