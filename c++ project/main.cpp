#include <iostream>
#include <queue>
#define max_int 201
using namespace std;

int n, r1, c1, r2, c2, check[max_int][max_int];
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

struct info {
    int x;
    int y;
};

void bfs(int x, int y) {
    queue<info> q;
    check[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        
        x = cur.x;
        y = cur.y;
        
        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 and nx < n and ny >= 0 and ny < n) {
                if(check[nx][ny] == -1) {
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void init () {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            check[i][j] = -1;
        }
    }
}

int main() {
    scanf("%d", &n);
    
    init();
    
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
    bfs(r1, c1);
    
    printf("%d\n", check[r2][c2]);
}
