#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[501][501];
bool check[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int result = 0;

void dfs(int x, int y, int sum_val, int cnt){
    
    result = max(result, sum_val);
    
    if(cnt == 4){
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false){
                check[nx][ny] = true;
                dfs(nx, ny, sum_val + d[nx][ny], cnt+1);
                check[nx][ny] = false;
            }
        }
    }
}

void exshape(int x, int y){
    
    //4가지 도형 모두 왼쪽 상단 (x, y)가 기준
    //ㅗ
    if(x-1>=0 && x<n && y>=0 && y+2<m)
        result = max(result, d[x][y]+d[x][y+1]+d[x][y+2]+d[x-1][y+1]);
    //ㅜ
    if(x>=0 && x+1<n && y>=0 && y+2<m)
        result = max(result, d[x][y]+d[x][y+1]+d[x][y+2]+d[x+1][y+1]);

    //ㅏ
    if(x>=0 && x+2<n && y>=0 && y+1<m)
        result = max(result, d[x][y]+d[x+1][y]+d[x+2][y]+d[x+1][y+1]);

    //ㅓ
    if(x-1>=0 && x+1<n && y>=0 && y+1<m)
        result = max(result, d[x][y]+d[x][y+1]+d[x-1][y+1]+d[x+1][y+1]);
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
            check[i][j] = true;
            dfs(i, j, d[i][j], 1);
            exshape(i, j);
            check[i][j] = false;
        }
    }

    cout << result << endl;
}
