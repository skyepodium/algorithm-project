#include <iostream>
<<<<<<< HEAD
#define max_int 101
using namespace std;

int t, n;
int a[max_int][max_int];
int d[max_int][max_int];

bool go(int i, int j){
    if(i>=n || j>=n) return 0;

    if(i==n-1 && j==n-1) return 1;

    int &ret = d[i][j];
    if(ret != -1) return ret;
    return ret = (go(i, j+a[i][j]) || go(i + a[i][j], j));

}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
                d[i][j] = -1;
            }
        }

        if(go(0, 0)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

}
=======
#include <vector>
#include <queue>
#include <algorithm>
// d
#define max_int 1001
using namespace std;


bool check[max_int];
vector<int> v[max_int];

int n, m, start_node, a, b;

void dfs(int node){
    check[node] = true;
    printf("%d ", node);
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int node = q.front();
        printf("%d ", node);
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &start_node);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    dfs(start_node);
    for(int i=0; i<=n; i++) check[i] = false;
    printf("\n");
    bfs(start_node);
}
>>>>>>> 147f2ced00735022bc8199e1eff21a9b3af8b49e
