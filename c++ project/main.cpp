#include <iostream>
#include <queue>
#define max_int 5001
using namespace std;

int n, a[max_int], check[max_int];
bool result;

bool bfs(int start){
    queue<int> q;
    check[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        int next = a[node];
        if(check[next] == 0){
            check[next] = check[node] + 1;
            q.push(next);
        }
    }
    if(check[start] == 3) return true;
    else return false;
}

void init(){
    for(int i=0; i<=n; i++) check[i] = 0;
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i=1; i<=n; i++){
        init();
        int check_result = bfs(i);
        if(check_result) result = true;
    }
    if(result) printf("YES\n");
    else printf("NO\n");
}
