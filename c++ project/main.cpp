#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^4)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

vector<int> a[101];
int check[101];
int n;
int start_node, end_node;

int bfs(int start){
    check[start] = 0;
    queue<int> q;
    q.push(start);
    int result = -1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            if(check[next] == 0){
                check[next] = check[node] + 1;
                q.push(next);
            }
            
            if(next == end_node){
                result = check[next];
            }
            
        }
    }
    
    return result;
}

int main(){
    
    cin >> n;
    cin >> start_node >> end_node;
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    cout << bfs(start_node) << endl;
    
}
