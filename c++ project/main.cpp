#include <iostream>
#include <vector>

#define max_int 40001
using namespace std;

int n, m, a, b, c;
struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];
int l[max_int];
int d[max_int];
int p[max_int];
bool check[max_int];

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

void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        info next = v[node][i];
        int n_node = next.cur;
        int n_cost = next.cost;
        if(!check[n_node]){
            l[n_node] = l[node] + 1;
            d[n_node] = n_cost + d[node];
            p[n_node] = node;
            dfs(n_node);
        }
    }
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    l[1] = 1;
    d[1] = 0;
    p[1] = 1;
    dfs(1);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%lld\n", d[a] + d[b] -2*d[lca(a, b)]);
    }
}