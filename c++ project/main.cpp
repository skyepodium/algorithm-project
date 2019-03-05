#include <iostream>
#include <queue>
#include <cstring>

#define max_val 2147483647
#define max_k 31
#define max_int 201
using namespace std;

int k, n, m;
int a[max_int][max_int];
int check[max_int][max_int][max_k];
int dx[] = {0, 0, 1, -1, 1, 2, 2, 1, -1, -2, -1, -2};
int dy[] = {-1, 1, 0, 0, 2, 1, -1, -2, 2, 1, -2, -1};

struct info{
    int x;
    int y;
    int remain;
};

void bfs(){
    queue<info> q;
    q.push({0, 0, k});
    check[0][0][k] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int remain = q.front().remain;
        q.pop();

        for(int i=0; i<12; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(i < 4){
                if(nx >=0 && nx<n && ny>=0 && ny<m && a[nx][ny] == 0){
                    if(check[nx][ny][remain] == -1){
                        check[nx][ny][remain] = check[x][y][remain] + 1;
                        q.push({nx, ny, remain});
                    }
                }
            }
            else{
                if(remain > 0 && nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny] == 0){
                    if(check[nx][ny][remain-1] == -1){
                        check[nx][ny][remain-1] = check[x][y][remain] + 1;
                        q.push({nx, ny, remain-1});
                    }
                }
            }

        }

    }
}

int main(){
    scanf("%d %d %d", &k, &m, &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    memset(check, -1, sizeof(check));

    bfs();

    int result = max_val;
    for(int i=0; i<=k; i++){
        if(check[n-1][m-1][i] != -1){
            result = min(result, check[n-1][m-1][i]);
        }
    }
    if(result == max_val) printf("%d\n", -1);
    else printf("%d\n", result);
}