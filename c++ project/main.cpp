#include <iostream>
#include <vector>

#define max_int 10001
using namespace std;

int n, m, a, b, first_node, second_node;
int p[max_int][18];
int log;
int timer;
int tin[max_int];
int tout[max_int];
vector<int> v[max_int];
int t;

void dfs(int node, int parent){
    tin[node] = ++timer;
    p[node][0] = parent;
    for(int i=1; i<=log; i++){
        p[node][i] = p[p[node][i-1]][i-1];
    }
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(next != parent){
            dfs(next, node);
        }
    }
    tout[node] = ++timer;
}

int upper(int first, int second){
    return (tin[first] <= tin[second] && tout[first] >= tout[second]);
}

int lca(int first, int second){
    if(upper(first, second)) return first;
    if(upper(second, first)) return second;
    
    for(int i=log; i>=0; i--){
        if(!upper(p[first][i], second)){
            first = p[first][i];
        }
    }
    return p[first][0];
}

void init(){
    for(int i=0; i<=n; i++){
        tin[i] = 0;
        tout[i] = 0;
        log = 0;
        timer = 0;
        v[i].clear();
        for(int j=0; j<18; j++){
            p[i][j] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d %d %d", &n, &m, &first_node, &second_node);
        init();
        
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(log = 1; (1<<log) < n; log++);
        log--;
        dfs(1, 1);
        
        int lca_node = lca(first_node, second_node);
        printf("#%d %d %d\n", test_case, lca_node, (tout[lca_node]-1-tin[lca_node])/2 + 1);
    }
    
    return 0;
}

