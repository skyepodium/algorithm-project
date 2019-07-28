#include <iostream>
#include <queue>
#define max_int 101
using namespace std;

int n, m, a[max_int][max_int], check[max_int][max_int][5];
int start_x, start_y, start_dir, end_x, end_y, end_dir;
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int first_dir[] = {3, 4}, second_dir[] = {1, 2};
int turn_dir[] = {1, 2, 3, 4};

struct info{
    int x, y, dir;
};

void bfs(){
    queue<info> q;
    check[start_x][start_y][start_dir] = 0;
    q.push({start_x, start_y, start_dir});
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        
        // 1. go k
        for(int k=1; k<=3; k++){
            int nx = x + dx[dir] * k;
            int ny = y + dy[dir] * k;
            
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == 1) break;
            
            if(check[nx][ny][dir] == -1 && a[nx][ny] == 0){
                check[nx][ny][dir] = check[x][y][dir] + 1;
                q.push({nx, ny, dir});
            }
        }
        
        // 2. turn
        int start_idx;
        if(dir < 3) start_idx = 2;
        else start_idx = 0;
        
        for(int i=start_idx; i<=start_idx + 1; i++){
            int ndir = turn_dir[i];
            if(check[x][y][ndir] == -1){
                check[x][y][ndir] = check[x][y][dir] + 1;
                q.push({x, y, ndir});
            }
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<=4; k++){
                check[i][j][k] = -1;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    init();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    scanf("%d %d %d %d %d %d", &start_x, &start_y, &start_dir, &end_x, &end_y, &end_dir);

    bfs();
    
    printf("%d\n", check[end_x][end_y][end_dir]);
}
