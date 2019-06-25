#include <iostream>
#define max_int 101
using namespace std;

int n, m, a[max_int][max_int], result = 0;
bool check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y){
    check[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny >= 0 && ny<m){
            if(!check[nx][ny]){
                dfs(nx, ny);//
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    
    while(true){
        int flag = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1){
                    dfs(i, j);
                    flag++;
                }
            }
        }
        if(flag == 0) break;
        result++;
    }
    printf("%d\n", result);
    
}
