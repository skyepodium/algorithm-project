#include <iostream>

#define max_int 51

/*
    시간 복잡도: O(tnm)
    공간 복잡도: O(nm)
    사용한 알고리즘: 반복문
    사용한 자료구조: 2차원 배열
 */
using namespace std;


/*
    n - 행의 크기
    m - 열의 크기
    t - 시간
    head_x, head_y - 공기 청정기의 위쪽 좌표
    tail_x, tail_y - 공기 청정기의 아래쪽 좌표
 */
int n, m, t, head_x = -1, head_y = -1, tail_x = -1, tail_y = -1, result = 0;

/*
    미세먼지의 정보를 저장할 2차원 배열 a
    미세먼지 확산 정보를 임시로 저장할 2차원 배열 dust_temp
 */
int a[max_int][max_int], dust_temp[max_int][max_int];

/*
    0~3 인덱스 값에 따라서
    0은 왼쪽
    1은 오른쪽
    2는 아래쪽
    3은 위쪽
*/
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};


// 미세먼지 확산
void dust_move() {
    
    for(int x=1; x<=n; x++){
        for(int y=1; y<=m; y++){
            
            // 미세먼지만 이동합니다. 공기청정기 칸은 건너 뜁니다.
            if(x == head_x && y == head_y) continue;
            if(x == tail_x && y == tail_y) continue;

            // 현재 칸 미세먼지의 크기
            int dust_size = a[x][y];
            int spread_size = dust_size / 5;
            // 확산 방향
            int move_cnt = 0;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 지도 밖으로 벗어나면 건너 뜁니다.
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                
                // 미세먼지 칸이면 건너 뜁니다.
                if(a[nx][ny] == -1) continue;
                
                // 확산 방향을 1증가시킵니다.
                move_cnt++;
                // 확산 되는 크기를 임시 저장합니다. 겹칠 수 있기 때문에 += 으로 처리합니다.
                dust_temp[nx][ny] += spread_size;
            }
            
            // 확산 방향의 개수만큼 미세먼지 양을 감소시킵니다.
            a[x][y] = dust_size - spread_size * move_cnt;
        }
    }
    
    
    // 미세먼지 확산 임시저장한 값 원래 지도에 더해주기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] += dust_temp[i][j];
            dust_temp[i][j] = 0;
        }
    }
}

// 바람의 이동
void wind() {
    
    // 공기청정기 - type 0 위쪽, type 1 아래족
    for(int type=0; type<=1; type++){

        int x, y, dir = 0;
        // 공기청정기 위쪽일때 시작방향은 위쪽
        if(type == 0){
            x = head_x;
            y = head_y;
            dir = 3;
        }
        // 공기청정기 아래쪽일때 시작방향은 아래족
        else{
            x = tail_x;
            y = tail_y;
            dir = 2;
        }
        
        // 한바퀴 돌아서 원래대로 돌아올때까지 반복
        while(true){
            // 다음 방향
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // 원래의 위치면 중단합니다.
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
            
            // 위쪽인데 아래쪽으로 넘어가려고 하면 방향을 왼쪽으로 바꿔줍니다.
            if(type == 0 && nx > head_x && ny == m){
                dir = 0;
                continue;
            }
            
            // 아래족인데 위쪽으로 넘어가려고 하면 방향을 왼쪽으로 바꿔줍니다.
            if(type == 1 && nx < tail_x && ny == m){
                dir = 0;
                continue;
            }
            
            // 다음칸이 공기청정기가 아닐때
            if(a[x][y] != - 1){
                a[x][y] = a[nx][ny];
                a[nx][ny] = 0;
            }


            // 이동
            x = nx;
            y = ny;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    
    // 1. 입력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            
            // 공기 청정기의 위치
            if(a[i][j] == -1){
                // 위쪽 좌표 저장
                if(head_x == -1 && head_y == -1){
                    head_x = i;
                    head_y = j;
                }
                // 아래쪽 좌표 좌정
                else {
                    tail_x = i;
                    tail_y = j;
                }
            }
        }
    }
    
    // 2. t초 동안 반복 수행
    for(int i=1; i<=t; i++){
        // 3. 미세먼지 확산
        dust_move();
        
        // 4. 바람의 이동
        wind();
    }
    
    // 5. 결과 계산 및 출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] != -1 ) result += a[i][j];
        }
    }
    printf("%d\n", result);
}
