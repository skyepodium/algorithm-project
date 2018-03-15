#include <iostream>
#include <queue>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

int d[301][301];
bool check[301][301];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

void bfs(int x, int y){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
            
                if(check[nx][ny] == false){
                    check[nx][ny] = true;
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                
            }
        }
    }
}

void clear_map(){
    
    for(int i=0; i<301; i++){
        for(int j=0; j<301; j++){
            d[i][j] = 0;
            check[i][j] = false;
        }
    }
}

int main(){
    
    int t;
    cin >> t;

    while(t--){
    
        cin >> n;
    
        int start_x, start_y;
        int end_x, end_y;
        
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;
    
        bfs(start_x, start_y);
        cout << d[end_x][end_y] << endl;
        
        clear_map();
        
    }
    
}
