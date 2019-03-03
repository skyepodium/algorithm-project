#include <iostream>
#include <vector>
#include <queue>

#define max_int 51
using namespace std;

int n, num, root_node, result = 0;
vector<int> v[max_int];
bool check[max_int];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        int child_cnt = 0;
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(!check[next]){
                child_cnt++;
                check[next] = true;
                q.push(next);
            }
        }
        if(child_cnt == 0){
            result++;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num != -1){
            v[num].push_back(i);
            v[i].push_back(num);
        } else {
            root_node = i;
        }
    }

    scanf("%d", &num);
    check[num] = true;

    if(!check[root_node]) bfs(root_node);

    printf("%d\n", result);
}