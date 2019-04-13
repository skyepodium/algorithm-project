#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

#define max_val 2147483647
#define max_int 34000000
using namespace std;

bool check[max_int];
int c[6][6];
// 0 오른쪽, 1 왼쪽, 2 아래쪽, 3 위쪽
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int t, n, x, y;
char dir;
int result;

struct info{
    int check;
    int head_x[10];
    int head_y[10];
    int tail_x[10];
    int tail_y[10];
    int dir[10];
    int cnt;
    int last_move;
};

queue<info> q;

void make_table();

void init();

void bfs(){
    while(!q.empty()){
        info cur = q.front();
        q.pop();

        // n개의 차에 대해서
        for(int i=0; i<n; i++){
            if(cur.last_move == i) continue;
            
            int c_check = cur.check;
            int c_head_x = cur.head_x[i];
            int c_head_y = cur.head_y[i];
            int c_tail_x = cur.tail_x[i];
            int c_tail_y = cur.tail_y[i];

            if(cur.dir[i] == 0 || cur.dir[i] == 1){

                for(int j=0; j<=4; j++){
                    if(j==0) continue;
                    
                    int n_head_x, n_head_y, n_tail_x, n_tail_y, first_x, first_y, last_x, last_y;
                    
                    if(c_head_y > c_tail_y){
                        n_head_x = c_head_x;
                        n_head_y = c_head_y;
                        n_tail_x = c_tail_x;
                        n_tail_y = c_tail_y;
                    }else{
                        n_head_x = c_tail_x;
                        n_head_y = c_tail_y;
                        n_tail_x = c_head_x;
                        n_tail_y = c_head_y;
                    }
                    
                    first_x = n_head_x;
                    first_y = n_head_y;
                    last_x = n_tail_x;
                    last_y = n_tail_y;
                    
                    n_head_x += j*dx[0];
                    n_head_y += j*dy[0];
                    n_tail_x += j*dx[0];
                    n_tail_y += j*dy[0];
                    
                    if(n_head_x >=1 && n_head_x<=5 && n_head_y>=1 && n_head_y<=5){
                        if(c_check & (1 << c[n_head_x][n_head_y])){
                            break;
                        }
                        else{
                            int t_check = c_check;
                            
                            t_check = t_check & ~(1 << c[first_x][first_y]);
                            t_check = t_check & ~(1 << c[last_x][last_y]);
                            
                            t_check = t_check | (1 << c[n_head_x][n_head_y]);
                            t_check = t_check | (1 << c[n_tail_x][n_tail_y]);
                            
                            if(!check[t_check]){
                                check[t_check] = true;
                                info next = cur;
                                next.head_x[i] = n_head_x;
                                next.head_y[i] = n_head_y;
                                next.tail_x[i] = n_tail_x;
                                next.tail_y[i] = n_tail_y;
                                next.cnt += 1;
                                next.check = t_check;
                                next.last_move = i;
                                q.push(next);
                            }
                        }
                    }
                    else{
                        if(i ==0 && n_head_y >= 6){
                            
//                            cout << "비트 출력" <<endl;
//                            for(int i=24; i>=0; i--){
//                                if(c_check & (1 << i)){
//                                    cout << i << endl;
//                                }
//                            }
//                            cout <<"out  cnt: " << cur.cnt + 1 << endl;
//                            cout << endl;
                            result = min(result, cur.cnt + 1);
                        }
                    }
                }
                
                
                for(int j=0; j<=3; j++){
                    if(j==0) continue;
                    
                    int n_head_x, n_head_y, n_tail_x, n_tail_y, first_x, first_y, last_x, last_y;
                    
                    if(c_head_y < c_tail_y){
                        n_head_x = c_head_x;
                        n_head_y = c_head_y;
                        n_tail_x = c_tail_x;
                        n_tail_y = c_tail_y;
                    }else{
                        n_head_x = c_tail_x;
                        n_head_y = c_tail_y;
                        n_tail_x = c_head_x;
                        n_tail_y = c_head_y;
                    }
                    
                    first_x = n_head_x;
                    first_y = n_head_y;
                    last_x = n_tail_x;
                    last_y = n_tail_y;
                    
                    n_head_x += j*dx[1];
                    n_head_y += j*dy[1];
                    n_tail_x += j*dx[1];
                    n_tail_y += j*dy[1];
                    
                    if(n_head_x >=1 && n_head_x<=5 && n_head_y>=1 && n_head_y<=5){
                        if(c_check & (1 << c[n_head_x][n_head_y])){
                            break;
                        }
                        else{
                            int t_check = c_check;
                            
                            t_check = t_check & ~(1 << c[first_x][first_y]);
                            t_check = t_check & ~(1 << c[last_x][last_y]);
                            
                            t_check = t_check | (1 << c[n_head_x][n_head_y]);
                            t_check = t_check | (1 << c[n_tail_x][n_tail_y]);
                            
                            if(!check[t_check]){
                                check[t_check] = true;
                                info next = cur;
                                next.head_x[i] = n_head_x;
                                next.head_y[i] = n_head_y;
                                next.tail_x[i] = n_tail_x;
                                next.tail_y[i] = n_tail_y;
                                next.cnt += 1;
                                next.check = t_check;
                                next.last_move = i;
                                q.push(next);
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                
            }
            else {


                for(int j=0; j<=3; j++){
                    if(j==0) continue;
                    
                    int n_head_x, n_head_y, n_tail_x, n_tail_y, first_x, first_y, last_x, last_y;

                    if(c_head_x > c_tail_x){
                        n_head_x = c_head_x;
                        n_head_y = c_head_y;
                        n_tail_x = c_tail_x;
                        n_tail_y = c_tail_y;
                    }else{
                        n_head_x = c_tail_x;
                        n_head_y = c_tail_y;
                        n_tail_x = c_head_x;
                        n_tail_y = c_head_y;
                    }
                    
                    first_x = n_head_x;
                    first_y = n_head_y;
                    last_x = n_tail_x;
                    last_y = n_tail_y;

                    n_head_x += j*dx[2];
                    n_head_y += j*dy[2];
                    n_tail_x += j*dx[2];
                    n_tail_y += j*dy[2];
                    
                    if(n_head_x >=1 && n_head_x<=5 && n_head_y>=1 && n_head_y<=5){
                        if(c_check & (1 << c[n_head_x][n_head_y])){
                            break;
                        }
                        else{
                            int t_check = c_check;
                            
                            t_check = t_check & ~(1 << c[first_x][first_y]);
                            t_check = t_check & ~(1 << c[last_x][last_y]);

                            t_check = t_check | (1 << c[n_head_x][n_head_y]);
                            t_check = t_check | (1 << c[n_tail_x][n_tail_y]);

                            if(!check[t_check]){
                                check[t_check] = true;
                                info next = cur;
                                next.head_x[i] = n_head_x;
                                next.head_y[i] = n_head_y;
                                next.tail_x[i] = n_tail_x;
                                next.tail_y[i] = n_tail_y;
                                next.cnt += 1;
                                next.check = t_check;
                                next.last_move = i;
                                q.push(next);
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                
                
                for(int j=0; j<=3; j++){
                    if(j==0) continue;
                    
                    int n_head_x, n_head_y, n_tail_x, n_tail_y, first_x, first_y, last_x, last_y;
                    
                    if(c_head_x < c_tail_x){
                        n_head_x = c_head_x;
                        n_head_y = c_head_y;
                        n_tail_x = c_tail_x;
                        n_tail_y = c_tail_y;
                    }else{
                        n_head_x = c_tail_x;
                        n_head_y = c_tail_y;
                        n_tail_x = c_head_x;
                        n_tail_y = c_head_y;
                    }
                    
                    first_x = n_head_x;
                    first_y = n_head_y;
                    last_x = n_tail_x;
                    last_y = n_tail_y;
                    
                    n_head_x += j*dx[3];
                    n_head_y += j*dy[3];
                    n_tail_x += j*dx[3];
                    n_tail_y += j*dy[3];
                    
                    if(n_head_x >=1 && n_head_x<=5 && n_head_y>=1 && n_head_y<=5){
                        if(c_check & (1 << c[n_head_x][n_head_y])){
                            break;
                        }
                        else{
                            int t_check = c_check;
                            
                            t_check = t_check & ~(1 << c[first_x][first_y]);
                            t_check = t_check & ~(1 << c[last_x][last_y]);
                            
                            t_check = t_check | (1 << c[n_head_x][n_head_y]);
                            t_check = t_check | (1 << c[n_tail_x][n_tail_y]);
                            
                            if(!check[t_check]){
                                check[t_check] = true;
                                info next = cur;
                                next.head_x[i] = n_head_x;
                                next.head_y[i] = n_head_y;
                                next.tail_x[i] = n_tail_x;
                                next.tail_y[i] = n_tail_y;
                                next.cnt += 1;
                                next.check = t_check;
                                next.last_move = i;
                                q.push(next);
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                
            }
        }
    }
}

//void bfs() {
//    while(!q.empty()){
//        info cur = q.front();
//        q.pop();
//
//        //n개의 차에 대해서
//        for(int i=0; i<n; i++){
//            int x1 = cur.x1[i];
//            int y1 = cur.y1[i];
//            int x2 = cur.x2[i];
//            int y2 = cur.y2[i];
//            int dir = cur.dir[i];
//            int last_move = cur.last_move;
//
//            // 방향
//            for(int j=0; j<4; j++){
//                int head_x = 0;
//                int head_y = 0;
//                int tail_x = 0;
//                int tail_y = 0;
//
//                if(j==0){
//                    if(y1 < y2){
//                        head_x = x2;
//                        head_y = y2;
//                        tail_x = x1;
//                        tail_y = y1;
//                    }
//                    else{
//                        head_x = x1;
//                        head_y = y1;
//                        tail_x = x2;
//                        tail_y = y2;
//                    }
//                }
//                else if(j==1){
//                    if(y1 < y2){
//                        head_x = x1;
//                        head_y = y1;
//                        tail_x = x2;
//                        tail_y = y2;
//                    }
//                    else{
//                        head_x = x2;
//                        head_y = y2;
//                        tail_x = x1;
//                        tail_y = y1;
//                    }
//                }
//                else if(j==2){
//                    if(x1 < x2){
//                        head_x = x2;
//                        head_y = y2;
//                        tail_x = x1;
//                        tail_y = y1;
//                    }
//                    else{
//                        head_x = x1;
//                        head_y = y1;
//                        tail_x = x2;
//                        tail_y = y2;
//                    }
//                }
//                else{
//                    if(x1 < x2){
//                        head_x = x1;
//                        head_y = y1;
//                        tail_x = x2;
//                        tail_y = y2;
//                    }
//                    else{
//                        head_x = x2;
//                        head_y = y2;
//                        tail_x = x1;
//                        tail_y = y1;
//                    }
//                }
//
//                cout << i << " " << x1 <<" "<<y1 << " "<<x2 << " " << y2 << endl;
//                cout << i << " " << head_x <<" "<<head_y << " "<<tail_x << " " << tail_y << endl;
//
//                // 칸 수 이동
//                for(int k=1; k<=4; k++){
//                    info next = cur;
//
//                    head_x += dx[j];
//                    head_y += dy[j];
//
//                    if(i==0 && dir == 0){
//                        if(head_y<=5){
//                            int front_c = c[head_x][head_y];
//                                int t_check = pow(2, front_c) + pow(2, c[head_x - dx[i]][head_y - dy[i]]);
//                                for(int l=0; l<n; l++){
//                                    if(i == l) continue;
//                                    t_check += (pow(2, c[cur.x1[i]][cur.y1[i]]) + pow(2, c[cur.x2[i]][cur.y2[i]]));
//                                }
//                                cout << t_check << endl;
//                                if(!check[t_check]){
//                                    next.c_map[front_c] = true;
//                                    next.c_map[c[tail_x][tail_y]] = false;
//                                    tail_x = head_x;
//                                    tail_y = head_y;
//                                    next.x1[i] = head_x;
//                                    next.y1[i] = head_y;
//                                    next.x2[i] = tail_x;
//                                    next.y2[i] = tail_y;
//                                    next.cnt += 1;
//                                    q.push(next);
//                                }
//                            }
//                            else{
//                                break;
//                            }
//                        }else{
//                            result = min(result, next.cnt + 1);
//                        }
//                    }
//                    else{
//                        if(head_x>=1 && head_y<=5){
//                            int front_c = c[head_x][head_y];
//                            if(!cur.c_map[front_c]){
//                                int t_check = pow(2, front_c) + pow(2, c[head_x - dx[i]][head_y - dy[i]]);
//                                for(int l=0; l<n; l++){
//                                    if(i == l) continue;
//                                    t_check += (pow(2, c[cur.x1[i]][cur.y1[i]]) + pow(2, c[cur.x2[i]][cur.y2[i]]));
//                                }
//                                if(!check[t_check]){
//                                    next.c_map[front_c] = true;
//                                    next.c_map[c[tail_x][tail_y]] = false;
//                                    tail_x = head_x;
//                                    tail_y = head_y;
//                                    next.x1[i] = head_x;
//                                    next.y1[i] = head_y;
//                                    next.x2[i] = tail_x;
//                                    next.y2[i] = tail_y;
//                                    next.cnt += 1;
//                                    q.push(next);
//                                }
//                            }
//                            else{
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//}

int main(){
    // 0. 테이블 제작
    make_table();

    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){

        // 1. 초기화
        init();

        scanf("%d", &n);

        info start;
        int t_check = 0;
        // 2. 차 정보 받음
        for(int i=0; i<n; i++){
            scanf("%d %d %c", &x, &y, &dir);

            int t_dir = -1;
            int x2 = 0;
            int y2 = 0;

            if(dir == 'E'){
                x2 = x;
                y2 = y-1;
                t_dir = 0;
            }
            else if(dir == 'S'){
                x2 = x-1;
                y2 = y;
                t_dir = 2;
            }
            else if(dir == 'W'){
                x2 = x;
                y2 = y+1;
                t_dir = 1;
            }
            else{
                x2=x+1;
                y2=y;
                t_dir = 3;
            }
            start.head_x[i] = x;
            start.head_y[i] = y;
            start.tail_x[i] = x2;
            start.tail_y[i] = y2;
            start.dir[i] = t_dir;

            int front_c = c[x][y];
            int back_c = c[x2][y2];
            t_check += (pow(2, front_c) + pow(2, back_c));
        }
        check[t_check] = true;
        start.check = t_check;
        start.cnt = 0;
        start.last_move = -1;
        q.push(start);

        bfs();
        if(result == max_val) result = -1;
        printf("#%d %d\n", test_case, result);
    }
}

void init() {
    result = max_val;
    memset(check, false, sizeof(check));
}

void make_table() {
    c[1][1] = 24;
    c[1][2] = 23;
    c[1][3] = 22;
    c[1][4] = 21;
    c[1][5] = 20;
    c[2][1] = 19;
    c[2][2] = 18;
    c[2][3] = 17;
    c[2][4] = 16;
    c[2][5] = 15;
    c[3][1] = 14;
    c[3][2] = 13;
    c[3][3] = 12;
    c[3][4] = 11;
    c[3][5] = 10;
    c[4][1] = 9;
    c[4][2] = 8;
    c[4][3] = 7;
    c[4][4] = 6;
    c[4][5] = 5;
    c[5][1] = 4;
    c[5][2] = 3;
    c[5][3] = 2;
    c[5][4] = 1;
    c[5][5] = 0;
}
