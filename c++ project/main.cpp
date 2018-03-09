#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(E)
//공간 복잡도: O(V)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 벡터, 1차원 배열

bool check[100001];
int dist[100001];

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(node-1 >= 0 && check[node-1] == 0){
            check[node-1] = true;
            dist[node-1] = dist[node] + 1;
            q.push(node-1);
        }
        
        if(node+1 <= 100000 && check[node+1] == 0){
            check[node+1] = true;
            dist[node+1] = dist[node] + 1;
            q.push(node+1);
        }
        
        if(node*2 <= 100000 && check[node*2] == 0){
            check[node*2] = true;
            dist[node*2] = dist[node] + 1;
            q.push(node*2);
        }
        
    }
}

int main(){
    
    int start, end;
    cin >> start >> end;
    
    bfs(start);
    cout << dist[end] << endl;
    
}

