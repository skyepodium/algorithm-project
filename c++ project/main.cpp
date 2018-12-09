#include <iostream>
#include <queue>

#define max_int 1001
using namespace std;

int n;
int a[max_int];
int check[max_int];

void bfs(int start){
    check[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        int cur_val = a[node];
        for(int i=1; i<=cur_val; i++){
            int next = node + i;
            if(next <= n && check[next] == 0){
                check[next] = check[node] + 1;
                q.push(next);
            }
        }

    }
    
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    bfs(1);
    if(check[n] == 0 && n!=1) check[n] = -1;
    printf("%d\n", check[n]);

    
}
