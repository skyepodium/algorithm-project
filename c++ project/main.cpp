#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int d[500][500];
bool check[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;

int cnt = 0;
int area = 0;
int max_area = 0;

void bfs(int x, int y){
    
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        area++;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check[nx][ny] == false && d[nx][ny] == 1){
                if(nx>=0 && nx<n && ny>=0 && ny<m) {
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
            cin >> d[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == false && d[i][j] == 1){
                bfs(i, j);
                cnt++;
                max_area = max(area, max_area);
                area = 0;
            }
        }
    }

    cout << cnt << endl;
    cout << max_area << endl;
    
}
