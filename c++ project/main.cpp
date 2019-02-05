#include <iostream>
#include <vector>
#include <queue>

#define max_int 501
using namespace std;

int n, m, a, b, result;
vector<int> v[max_int];
int check[max_int];

void bfs(int start){
    check[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == 0){
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    check[1] = 1;
    bfs(1);
    result = 0;
    for(int i=2; i<=n; i++){
        if(check[i] == 2 || check[i] == 3){
            result++;
        }
    }

    printf("%d\n", result);
}