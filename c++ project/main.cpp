#include <iostream>
#include <queue>

#define max_int 1001
#define max_val 1001 * 1001

using namespace std;

int n, m, k, check[max_int][max_int][11][2], result = max_val, n_day;
char a[max_int][max_int];
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};

struct info {
    int x, y, use, day;
};

void bfs(int x, int y, int use, int day) {
    queue<info> q;
    check[x][y][0][0] = 1;
    q.push({x, y, 0, 0});
    
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        
        x = cur.x;
        y = cur.y;
        use = cur.use;
        day = cur.day;
        
        n_day = day == 0 ? 1 : 0;
        
        if (check[x][y][use][n_day] == max_val) {
            check[x][y][use][n_day] = check[x][y][use][day] + 1;
            q.push({x, y, use, n_day});
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (a[nx][ny] == '0' && check[nx][ny][use][n_day] > check[x][y][use][day] + 1) {
                check[nx][ny][use][n_day] = check[x][y][use][day] + 1;
                q.push({nx, ny, use, n_day});
            }
            
            if (a[nx][ny] == '1' && use < k && day == 0 && check[nx][ny][use][n_day] > check[x][y][use][day] + 1) {
                check[nx][ny][use + 1][n_day] = check[x][y][use][day] + 1;
                q.push({nx, ny, use + 1, n_day});
            }
        }
    }
}

void init () {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int a=0; a<=k; a++) {
                for(int b=0; b<2; b++) {
                    check[i][j][a][b] = max_val;
                }
            }
        }
    }
}


int main () {
    scanf("%d %d %d", &n, &m, &k);
    
    init();
    
    for(int i=0; i<n; i++) {
        scanf("%s", a[i]);
    }
    
    bfs(0, 0, 0, 0);
    
    for(int i=0; i<=k; i++) {
        for(int j=0; j<2; j++) {
            result = min(result, check[n-1][m-1][i][j]);
        }
    }
    
    if (result == max_val) result = -1;
    
    printf("%d\n", result);
}
