#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(E) - 간선의 갯수
//공간 복잡도: O(E) - 간선의 갯수
//사용한 알고리즘: DFS
//사용한 자료구조: 1차원 벡터, 1차원 배열

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
    
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
