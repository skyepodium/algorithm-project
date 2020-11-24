#include <iostream>
#include <queue>
#include <vector>
#define max_int 300001
using namespace std;

int n, m, k, x, check[max_int], start_point, end_point, cnt = 0;
vector<int> v[max_int];

void bfs(int start_node) {
    queue<int> q;
    check[start_node] = 0;
    q.push(start_node);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++) {
            int next = v[node][i];
            
            if(check[next] == -1) {
                check[next] = check[node] + 1;
                q.push(next);
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
    scanf("%d %d %d %d", &n, &m, &k, &x);
    
    init();
    
    for(int i=0; i<m; i++) {
        scanf("%d %d", &start_point, &end_point);
        v[start_point].push_back(end_point);
    }
    
    bfs(x);

    for(int i=1; i<=n; i++) {
        if(k == check[i]) {
            printf("%d\n", i);
            cnt++;
        }
    }
    
    if(cnt == 0) {
        printf("-1\n");
    }
}
