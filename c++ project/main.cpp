#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열, queue

int d[101][101];
bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;


void bfs(int x, int y){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >=0 && nx<n && ny >=0 && ny <m){
                if(check[nx][ny] == false && d[nx][ny] == 1){
                    d[nx][ny] = d[x][y] + 1;
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    bfs(0, 0);
    cout << d[n-1][m-1] << endl;
}
