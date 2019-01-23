#include <iostream>
#include <queue>
#include <vector>

#define max_int 100001

using namespace std;

int n, m, start_node, a, b;
bool check[max_int];
vector<int> v[max_int];

void bfs(int start){
    queue<int> q;
    check[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        printf("%d ", node);
        q.pop();
        for(int i=0; i<(int)v[node].size(); i++){
            int next = v[node][i];
            if(!check[next]){
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

    bfs(start_node);
    printf("\n");
}
