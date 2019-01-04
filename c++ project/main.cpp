#include <iostream>
#include <vector>
#include <queue>

#define max_int 101
using namespace std;

int n, start_node, a, b, result, max_node;
bool d[max_int][max_int];
int check[max_int];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next=1; next<=100; next++){
            if(d[node][next] && check[next] == false){
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}


void init(){
    result = 0;
    max_node = 0;
    for(int i=1; i<max_int; i++){
        check[i] = 0;
        for(int j=1; j<max_int; j++){
            d[i][j] = false;
        }
    }
}

int main(){
    for(int test_case=1; test_case<=1; test_case++){
        scanf("%d %d", &n, &start_node);
        init();

        for(int i=0; i<n/2; i++){
            scanf("%d %d", &a, &b);
            if(d[a][b] == false){
                d[a][b] = true;
            }
        }
        bfs(start_node);
        for(int i=100; i>=1; i--){
            if(result < check[i]){
                result = check[i];
                max_node = i;
            }
        }
        printf("#%d %d\n", test_case, max_node);
    }
}