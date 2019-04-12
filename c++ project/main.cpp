#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
#define max_int 11
using namespace std;

int n, m, bx, by, rx, ry;
char a[max_int][max_int];
int check[max_int][max_int][max_int][max_int];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int result = 11;

struct info{
    int bx;
    int by;
    int rx;
    int ry;
    int dir;
    int cnt;
};

queue<info> q;

void bfs(){
    while(!q.empty()){
        info cur = q.front();
        q.pop();

        // 방향
        for(int i=0; i<4; i++){
            int c_bx = cur.bx;
            int c_by = cur.by;
            int c_rx = cur.rx;
            int c_ry = cur.ry;
            int c_dir = cur.dir;
            int c_cnt = cur.cnt;

            if(c_dir == i) continue;

            int n_bx = c_bx;
            int n_by = c_by;
            int n_rx = c_rx;
            int n_ry = c_ry;

            bool b_find = false;
            bool r_find = false;

            for(int j=0; j<=max_int; j++){
                n_bx += dx[i];
                n_by += dy[i];

                if(n_bx>=0 && n_bx <n && n_by >=0 && n_by<m){
                    if(a[n_bx][n_by] == '#'){
                        n_bx -= dx[i];
                        n_by -= dy[i];
                        break;
                    } else if(a[n_bx][n_by] == 'O'){
                        b_find = true;
                        false;
                    }
                }
            }

            for(int j=0; j<=max_int; j++){
                n_rx += dx[i];
                n_ry += dy[i];

                if(n_rx>=0 && n_rx <n && n_ry >=0 && n_ry<m) {
                    if(a[n_rx][n_ry] == '#'){
                        n_rx -= dx[i];
                        n_ry -= dy[i];
                        break;
                    } else if(a[n_rx][n_ry] == 'O'){
                        r_find = true;
                        false;
                    }

                }
            }

            if(n_bx == n_rx && n_by == n_ry){
                if(i==0){
                    if(c_by > c_ry){
                        n_ry--;
                    }
                    else{
                        n_by--;
                    }
                }
                else if(i==1){
                    if(c_bx > c_rx){
                        n_rx--;
                    }
                    else{
                        n_bx--;
                    }
                }
                else if(i==2){
                    if(c_by < c_ry){
                        n_ry++;
                    }
                    else{
                        n_by++;
                    }
                }
                else{
                    if(c_bx < c_rx){
                        n_rx++;
                    }
                    else{
                        n_bx++;
                    }
                }
            }


            if(b_find || r_find){
                if(b_find && !r_find) continue;
                else if(b_find && r_find) continue;
                else if(!b_find && r_find){
                    result = min(result, c_cnt + 1);
                    continue;
                }
            }

            if(check[n_bx][n_by][n_rx][n_ry] == -1){
                check[n_bx][n_by][n_rx][n_ry] = c_cnt + 1;
                if(check[n_bx][n_by][n_rx][n_ry] <= 10){
                    q.push({n_bx, n_by, n_rx, n_ry, i, c_cnt + 1});
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%s", a[i]);
        for(int j=0; j<m; j++){
            if(a[i][j] == 'B'){
                bx = i;
                by = j;
                a[i][j] = '.';
            }
            else if(a[i][j] == 'R'){
                rx = i;
                ry = j;
                a[i][j] = '.';
            }
        }
    }

    memset(check, -1, sizeof(check));
    check[bx][by][rx][ry] = 0;

    for(int i=0; i<4; i++){
        q.push({bx, by, rx, ry, i, 0});
    }

    bfs();

    if(result == 11) result = -1;
    printf("%d\n", result);
}