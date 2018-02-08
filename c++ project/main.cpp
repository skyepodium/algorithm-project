#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int a[30][30];
int d[30][30];
int n;
int ans[25*25];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx<n && 0<= ny && ny <n){
            if(a[nx][ny] == 1 && d[nx][ny] == 0){
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 1 && d[i][j] == 0){
                dfs(i, j, ++cnt);
            }
        }
    }
    cout << cnt << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[d[i][j]] +=1;
        }
    }
    sort(ans+1, ans+1+cnt);
    
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << endl;
    }
    
}
