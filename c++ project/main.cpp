#include <iostream>
#include <cstring>
#include <queue>

#define max_int 10

using namespace std;

int n, m, r_x, r_y, b_x, b_y, end_x, end_y;
int check[max_int][max_int][max_int][max_int];
char a[max_int][max_int];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct info{
    int r_x;
    int r_y;
    int b_x;
    int b_y;
    int cnt;
};

queue<info> q;

void bfs() {
    while(!q.empty()){
        info cur = q.front();
        q.pop();

        int c_rx = cur.r_x;
        int c_ry = cur.r_y;
        int c_bx = cur.b_x;
        int c_by = cur.b_y;
        int c_cnt = cur.cnt;

        int n_rx = 0;
        int n_ry = 0;
        int n_bx = 0;
        int n_by = 0;

        for(int i=0; i<4; i++){

            // 파랑색 먼저 검사
            bool flag = true;
            for(int j=1; j<=n; j++){
                n_bx = c_bx + dx[i]*j;
                n_by = c_by + dy[i]*j;

                if(n_bx>=0 && n_bx<n && n_by>=0 && n_by<n){
                    if(a[n_bx][n_by] == 'O'){
                        flag = false;
                        break;
                    }else if(a[n_bx][n_by] == '.'){

                    }else {
                        n_bx = n_bx - dx[i];
                        n_by = n_by - dy[i];
                        break;
                    }
                }
            }

//            n_rx = c_rx + dx[i]*j;
//            n_ry = c_ry + dy[i]*j;

        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%s", a[i]);
        for(int j=0; j<m; j++){
            if(a[i][j] == 'R'){
                r_x = i;
                r_y = j;
            }else if(a[i][j] == 'B'){
                b_x = i;
                b_y = j;
            }else if(a[i][j] == 'O'){
                end_x = i;
                end_y = j;
            }
        }
    }

    memset(check, -1, sizeof(check));
    check[r_x][r_y][b_x][b_y] = 0;

    q.push({r_x, r_y, b_x, b_y, 0});
    bfs();
}