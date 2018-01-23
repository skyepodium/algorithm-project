#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//시간 복잡도: O(E)
//공간 복잡도: O(E)
//사용한 알고리즘: BFS, DFS, sort
//사용한 자료구조: 2차원 벡터, 1차원 배열

vector<int> a[10001];
bool check[10001];

void dfs(int node){
    check[node] = true;
    cout << node << " ";
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}


int main(){
    
    int n, m, start;
    cin >> n >> m >> start;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(start);
    cout << endl;
    bfs(start);
    cout << endl;
    
}

