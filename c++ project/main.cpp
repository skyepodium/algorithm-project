#include <iostream>
#include <string>
#include <queue>

#define max_int 1001
#define max_length 31
using namespace std;

int n, k, start_node, end_node, p[max_int];
bool check[max_int];
char a[max_int][max_length];

void go(int node) {
    if(node == p[node]) {
        printf("%d ", node);
        return;
    }
    
    go(p[node]);
    
    printf("%d ", node);
}

void bfs() {
    queue<int> q;
    check[start_node] = true;
    p[start_node] = start_node;
    q.push(start_node);
    
    while(!q.empty()) {
        int node = q.front();
        
        q.pop();
        
        char *cur_num = a[node];
        
        for(int i=1; i<=n; i++) {
            int next_node = i;
            if(!check[next_node]) {
                
                char *next_num = a[next_node];
                
                int diff_cnt = 0;
                for(int idx=0; idx<k; idx++) {
                    if(cur_num[idx] != next_num[idx]) diff_cnt++;
                }
                
                if(diff_cnt == 1) {
                    p[next_node] = node;
                    check[next_node] = true;
                    q.push(next_node);
                }
            }
        }
    }
}

void solve() {
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++) {
        scanf("%s", a[i]);
    }
    
    scanf("%d %d", &start_node, &end_node);
    
    bfs();
    
    if(!check[end_node]) {
        printf("-1\n");
    }
    else {
        go(end_node);
        printf("\n");
    }
}

int main(){
    solve();
}
