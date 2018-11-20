#include <iostream>
#include <queue>

#define max_int 1001
using namespace std;

int n, m, k;
int d[max_int][max_int];
int check[max_int][max_int][11];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x;
    int y;
    int use;
};

int bfs(){
    queue<info> q;
    check[1][1][0] = 1;
    q.push({1, 1, 0});
    while(!q.empty()){
        info node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;
        int use = node.use;
        
        if(x == n && y == m){
            return check[x][y][use];
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                
                if(check[nx][ny][use] == 0 && d[nx][ny] == 0){
                    check[nx][ny][use] = check[x][y][use] + 1;
                    q.push({nx, ny, use});
                }
                else{
                    if(check[nx][ny][use+1] == 0 && use <= k-1){
                        check[nx][ny][use+1] = check[x][y][use] + 1;
                        q.push({nx, ny, use+1});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    printf("%d\n", bfs());
}
