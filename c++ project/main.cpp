#include <iostream>
#include <queue>
#define max_int 101
using namespace std;

int n, m, check[max_int][max_int], dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
char a[max_int][max_int];

struct info{
    int x, y;
};

void bfs(){
    queue<info> q;
    check[1][1] = 1;
    q.push({1, 1});
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            if(a[nx][ny] == '1' && check[nx][ny] == 0){
                check[nx][ny] = check[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%s", a[i] + 1);
    }
    
    bfs();
    
    printf("%d\n", check[n][m]);
}
