#include <iostream>
#include <algorithm>

using namespace std;

int d[500][500];
bool check[500][500];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int cnt = 0;
int max_area = 0;
int area = 0;

void dfs(int x, int y){
    
    check[x][y] = true;
    area++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
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
            if(d[i][j] == 1 && check[i][j] == false){
                dfs(i, j);
                cnt++;
                max_area = max(area, max_area);
                area = 0;
            }
        }
    }
    
    cout << cnt << endl;
    cout << max_area << endl;
}
