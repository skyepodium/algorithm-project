#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열, queue

vector<int> a[5001];
int n, m;
bool check[101];

int cnt = 0;
void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    cnt++;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
}


int main(){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        memset(check, false, sizeof(check));
        if(check[i] == false){
            cnt = 0;
            bfs(i);
            cout << cnt << endl;
        }
    }
    
}
