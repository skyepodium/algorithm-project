#include <iostream>
#define max_int 101
using namespace std;

int n, m, dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0}, w_result, b_result, cnt;
bool check[max_int][max_int];
char a[max_int][max_int];

void dfs(int x, int y, char soldier) {
    check[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        
        if (!check[nx][ny] && a[nx][ny] == soldier) {
            dfs(nx, ny, a[nx][ny]);
        }
    }
}

int main () {
    scanf("%d %d", &m, &n);
    
    for(int i=0; i<n; i++) {
        scanf("%s", a[i]);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (!check[i][j]) {
                cnt = 0;

                dfs(i, j, a[i][j]);

                if(a[i][j] == 'W') {
                    w_result += cnt * cnt;
                }
                else{
                    b_result += cnt * cnt;
                }
            }
        }
    }
    
    printf("%d %d\n", w_result, b_result);
}
