#include <iostream>
#include <queue>
#define max_int 10001

using namespace std;

int n, a[max_int], start_point, end_point, check[max_int];

void bfs(int start_node) {
    queue<int> q;
    check[start_node] = 0;
    q.push(start_node);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i=1; node + a[node] * i <= n; i++) {
            int next_node = node + a[node] * i;
            
            if(check[next_node] == -1) {
                check[next_node] = check[node] + 1;
                q.push(next_node);
            }
        }
        
        for(int i=1; node - a[node] * i >= 1; i++) {
            int next_node = node - a[node] * i;
            
            if(next_node <= n && check[next_node] == -1) {
                check[next_node] = check[node] + 1;
                q.push(next_node);
            }
        }
    }
}

void init () {
    for(int i=0; i<=n; i++) {
        check[i] = -1;
    }
}

int main () {
    scanf("%d", &n);
    
    init();
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d %d", &start_point, &end_point);
    
    bfs(start_point);
    
    printf("%d\n", check[end_point]);
}

