#include <iostream>
#include <queue>
#include <algorithm>
#define max_int 51
#define max_val 101
using namespace std;

int n, m, a[max_int][max_int], check[max_int][max_int], safe_dist, result;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

struct info{
    int x, y;
};

void bfs(int x, int y){
    queue<info> q;
    check[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        x = cur.x;
        y = cur.y;
        
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(check[nx][ny] != -1) continue;
            
            check[nx][ny] = check[x][y] + 1;
            
            if(a[nx][ny] == 1)  safe_dist = min(safe_dist, check[nx][ny]);

            q.push({nx, ny});
        }
    }
}

void init(){
    safe_dist = max_val;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            check[i][j] = -1;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 0){
                
                init();
                
                bfs(i, j);
                
                result = max(result, safe_dist);
            }
        }
    }
    
    printf("%d\n", result);
}
