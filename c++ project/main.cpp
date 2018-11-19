#include <iostream>
#include <queue>
#include <algorithm>

#define max_int 1001
#define max_val 2147483647
using namespace std;

int n, m;
int a[max_int][max_int];
int check[max_int][max_int][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x;
    int y;
    bool use;
};

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
            check[i][j][0] = max_val;
            check[i][j][1] = max_val;
        }
    }
    
    queue<info> q;
    check[0][0][0] = 1;
    q.push({0, 0, false});
    while(!q.empty()){
        info node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;
        bool use = node.use;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                
                if(a[nx][ny] == 0 && check[nx][ny][use] > check[x][y][use] + 1){
                    check[nx][ny][use] = check[x][y][use] + 1;
                    q.push({nx, ny, use});
                }
                
                if(a[nx][ny] == 1 && use == false && check[nx][ny][1] > check[x][y][0] + 1){
                    check[nx][ny][1] = check[x][y][0] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    
    if(check[n-1][m-1][false] == max_val && check[n-1][m-1][true] == max_val) printf("-1\n");
    else printf("%d\n", min(check[n-1][m-1][false], check[n-1][m-1][true]));
}

