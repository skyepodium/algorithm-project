#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 배열, queue

int d[1001][1001];
bool check[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int tomato_cnt = 0;
int n, m;

queue<pair<int, int>> q;

void bfs(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        tomato_cnt--;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny >= 0 && ny < m){
                if(check[nx][ny] == false && d[nx][ny] == 0){
                    check[nx][ny] = true;
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}



int main(){

    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d[i][j];
            if(d[i][j] == 1 || d[i][j] == 0){
                tomato_cnt++;
            }
            
            if(d[i][j] == 1){
                q.push(make_pair(i, j));
                check[i][j] = true;
            }
            
        }
    }

    bfs();

    int day = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            day = max(day, d[i][j]);
        }
    }
    
    if(tomato_cnt == 0){
        cout << day-1 << endl;
    }else{
        cout << -1 << endl;
    }
    
    
}
