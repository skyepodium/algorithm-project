#include <iostream>
#include <vector>
#include <queue>
#define max_int 10001
using namespace std;

int t, n, m, l, a, b, c, check[max_int], result;

vector<int> v[max_int];

queue<int> q;

void bfs(){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == -1){
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}

void init(){
    result = 0;
    for(int i=1; i<=n; i++){
        check[i] = -1;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d %d", &n, &m, &l);
        
        init();
        
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }
        
        for(int i=0; i<l; i++){
            scanf("%d", &c);
            check[c] = 0;
            q.push(c);
        }
        
        bfs();
        
        printf("%d\n", result);
    }
}
