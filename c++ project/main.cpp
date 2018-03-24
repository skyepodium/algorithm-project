#include <iostream>
#include <algorithm>

using namespace std;

int d[101][101];
bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int cnt = 0;
void dfs(int x, int y, int color){
    check[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0  && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false && d[nx][ny] == color && d[nx][ny] != 0){
                dfs(nx, ny, d[nx][ny]);
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
    
    int total_cnt = 0;
    int max_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == false && d[i][j] != 0){
                dfs(i, j, d[i][j]);
                total_cnt++;
                max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }
        }
    }

    cout << total_cnt <<" "<< max_cnt << endl;
    
    
}
