#include <iostream>
#define max_int 51
using namespace std;

int t, n, m, k, a[max_int][max_int], x, y, dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0}, result;
bool check[max_int][max_int];

void dfs(int x, int y){
    check[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!check[nx][ny] && a[nx][ny] == 1){
            dfs(nx, ny);
        }
    }
}

void init(){
    result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a[i][j] = 0;
            check[i][j] = false;
        }
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d %d", &n, &m, &k);
        
        init();
        
        for(int i=0; i<k; i++){
            scanf("%d %d", &x, &y);
            a[x][y] = 1;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!check[i][j] && a[i][j] == 1){
                    result++;
                    dfs(i, j);
                }
            }
        }  
        
        printf("%d\n", result);
    }
    
}
