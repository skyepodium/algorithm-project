#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: DFS
//사용한 자료구조: 1차원 배열, 2차원 벡터

vector<int> a[1001];
bool check[1001];

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        
        if(check[next] == false){
            dfs(next);
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
                dfs(i);
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
