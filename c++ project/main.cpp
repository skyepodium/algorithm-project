#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열, queue

int n, m;
int a[100][100];
bool check[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y){
    check[x][y] = true;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<m && 0<=ny && ny<n){
                if(a[nx][ny] == 1 && check[nx][ny] == false){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    a[nx][ny] = a[x][y]+1;
                    
                }
            }
        }
        
    }
}

int main(){
    
    cin >> n >> m;
    
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    bfs(0, 0);
    
    cout << a[m-1][n-1] << endl;
}
