#include <iostream>

#define max_int 51
using namespace std;

int n, m, t, head_x = -1, head_y = -1, tail_x = -1, tail_y = -1, result = 0;

int a[max_int][max_int], dust_temp[max_int][max_int];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void dust_move() {
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            
            if(i == head_x && j == head_y) continue;
            if(i == tail_x && j == tail_y) continue;

            
            int x = i;
            int y = j;
            
            int dust_size = a[x][y];
            int move_cnt = 0;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                
                if(a[nx][ny] == -1) {
                    continue;
                }
                
                move_cnt++;
                dust_temp[nx][ny] += dust_size / 5;
            }
            
            a[x][y] = dust_size - (dust_size / 5) * move_cnt;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] += dust_temp[i][j];
            dust_temp[i][j] = 0;
        }
    }
}

void wind() {
    
    // type 0 head, type 2 tail
    for(int type=0; type<=1; type++){

        int x, y, dir = 0;
        if(type == 0){
            x = head_x;
            y = head_y;
            dir = 3;
        }
        else{
            x = tail_x;
            y = tail_y;
            dir = 2;
        }
        
        while(true){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx == head_x && ny == head_y) break;
            if(nx == tail_x && ny == tail_y) break;
            
            // 오른쪽 끝
            if(ny > m) {
                if(type == 0) dir = 2;
                else dir = 3;
                continue;
            }
            // 위쪽 끝
            else if(nx < 1){
                dir = 1;
                continue;
            }
            // 아래쪽 끝
            else if(nx > n){
                dir = 1;
                continue;
            }
            
            if(type == 0 && nx > head_x && ny == m){
                dir = 0;
                continue;
            }
            
            if(type == 1 && nx < tail_x && ny == m){
                dir = 0;
                continue;
            }
            
            if(a[x][y] != - 1){
                a[x][y] = a[nx][ny];
                a[nx][ny] = 0;
            }else{
                a[nx][ny] = 0;
            }
            
            x = nx;
            y = ny;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            
            // 공기 청정기의 위치
            if(a[i][j] == -1){
                if(head_x == -1 && head_y == -1){
                    head_x = i;
                    head_y = j;
                }else {
                    tail_x = i;
                    tail_y = j;
                }
            }
        }
    }
    
    for(int i=1; i<=t; i++){
        dust_move();
        
        wind();
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] != -1 ) result += a[i][j];
        }
    }
    printf("%d\n", result);
}
