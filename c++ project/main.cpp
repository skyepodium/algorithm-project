#include <iostream>
#include <vector>
#include <queue>
#define max_int 100001
using namespace std;

int n, m, start_node, end_node, a, b;
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
    scanf("%d %d %d %d", &n, &m, &start_node, &end_node);

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(start_node);

    printf("%d\n", check[end_node] - 1);

}