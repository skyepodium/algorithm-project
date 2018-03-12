#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: BFS
//사용한 자료구조: 1차원 배열, 2차원 벡터, 큐

vector<int> a[1001];
bool check[1001];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
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
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++){
            int v;
            cin >> v;
            a[i].push_back(v);
        }
        
        int cnt = 0;
        
        for(int i=1; i<=n; i++){
            if(check[i] == false){
                bfs(i);
                cnt++;
            }
        }
        cout << cnt << endl;
        memset(check, false, sizeof(check));
        for(int i=0; i<1001; i++){
            a[i].clear();
        }

    }
    
}

