#include <iostream>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, Top-down
//사용한 자료구조: 2차원 배열

int a[501][501];
int d[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;

int go(int x, int y){
    
    if(x == 0 && y ==0){
        return 1;
    }
    
    if(d[x][y] > -1){
        return d[x][y];
    }
    
    d[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(a[nx][ny] > a[x][y]){
                d[x][y] = d[x][y] + go(nx, ny);
            }
        }
    }
    
    return d[x][y];
}

int main(){
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }

    cout << go(n-1, m-1) << endl;
    
}
