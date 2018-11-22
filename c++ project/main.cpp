#include <iostream>
#include <queue>

#define max_int 51
using namespace std;

int t, m, n, k, a, b;
int d[max_int][max_int];
bool check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y){
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &m, &n, &k);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                check[i][j] = 0;
                d[i][j] = 0;
            }
        }
        
        for(int i=0; i<k; i++){
            scanf("%d %d", &a, &b);
            d[b][a] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == false && d[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
    }
}
