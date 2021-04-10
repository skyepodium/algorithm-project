#include <iostream>
#include <vector>
#include <queue>

#define max_int 51

/*
 시간 복잡도: K * N^2
 공간 복잡도: N^2
 사용한 알고리즘: 반복문
 사용한 자료구조: 큐
*/

using namespace std;

int N, M, K, r, c, m, s, d, result;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 절대값 함수입니다.
int abs(int num) {
    return num < 0 ? num * -1 : num;
}

// 파이어볼을 구조체로 정의했습니다.
// 1) 질량, 2) 속도, 3) 방향을 가집니다.
struct fireball {
    int m, s, d;
};

// N*N 1칸에 여러개의 파이어볼이 있을 수 있기 때문에 큐를 사용했습니다.
queue<fireball> base[max_int][max_int];

// 현재 1칸의 파이어볼들의 정보를 저장하는 구조체입니다.
// 1) 개수, 2) 질량의 합, 3) 속도의 합, 3) 방향, 4) 전부 홀수인가? 5) 전부 짝수인가?
struct info {
    int cnt, mass, speed, direction;
    bool is_odd, is_even;
};

// N*N 칸에 정보를 저장할 수 있도록 2차원 배열로 선언합니다.
info sum_info[max_int][max_int];

// N*N 한칸에 저장된 파이어 볼들의 정보를 초기화 합니다.
void clear_sum_info() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            sum_info[i][j] = {0, 0, 0, 0, true, true};
        }
    }
}

// 파이어볼 들을 이동시킵니다.
void move_fire_ball() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            // 현재의 큐가 비어있기 전까지 진행합니다.
            while (!base[i][j].empty()) {
                fireball cur = base[i][j].front();
                base[i][j].pop();

                // 방향 * 속력 만큼 이동시킵니다.
                int nx = i + dx[cur.d] * cur.s;
                int ny = j + dy[cur.d] * cur.s;

                // 만약 영역을 벗어나면, 자리를 계산하고 넣어줍니다.
                if (nx < 1 || nx > N || ny < 1 || ny > N) {
                    if (nx < 1) nx = (abs(nx) % N) * -1 + N;
                    if (ny < 1) ny = (abs(ny) % N) * -1 + N;
                    if (nx > N) nx = nx % N == 0 ? N : nx % N;
                    if (ny > N) ny = ny % N == 0 ? N : ny % N;
                }
                    
                // 정보를 업데이트 해줍니다.
                sum_info[nx][ny].cnt++;
                sum_info[nx][ny].mass += cur.m;
                sum_info[nx][ny].speed += cur.s;
                sum_info[nx][ny].direction += cur.d;

                if (cur.d % 2 == 0) sum_info[nx][ny].is_odd = false;
                if (cur.d % 2 == 1) sum_info[nx][ny].is_even = false;

            }
        }
    }
}

// 파이어 볼들을 분리합니다.
void split_fire_ball() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            // 만약 0개이면 진행하지 않습니다.
            if (sum_info[i][j].cnt <= 0) continue;

            // 1개인 경우 1) 질량의 합에 넣어주고, 2) 큐에 넣어줍니다.
            if (sum_info[i][j].cnt == 1) {
                result += sum_info[i][j].mass;
 
                base[i][j].push({ sum_info[i][j].mass, sum_info[i][j].speed, sum_info[i][j].direction });

                continue;
            }

            // 2개 이상인 경우
            int mass = sum_info[i][j].mass / 5;
            int speed = sum_info[i][j].speed / sum_info[i][j].cnt;

            // 질량이 0보다 작으면 소멸시킵니다.
            if (mass <= 0) continue;

            int start_idx = 1;

            // 전부 홀수 또는 짝수 이면 0, 2, 4, 6을 넣어줍니다.
            if (sum_info[i][j].is_odd || sum_info[i][j].is_even) start_idx = 0;

            for (int idx = start_idx; idx < 8; idx += 2) {
                base[i][j].push({ mass, speed, idx });
                
                result += mass;
            }
        }
    }
}


int main() {
    // 1. 입력
    scanf("%d %d %d", &N, &M, &K);

    // M개의 파이어볼을 입력받고 N&N으로 구성된 큐에 저장합니다.
    // N*N 1칸에 여러개의 파이어볼이 있을 수 있기 때문에 큐를 사용했습니다.
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
        base[r][c].push({ m, s, d });
    }

    // 2. K번 반복합니다.
    while (K--) {
        // 현재의 질량의 합을 전부 초기화 합니다.
        result = 0;

        // N*N 한칸에 저장된 파이어 볼들의 정보를 초기화 합니다.
        clear_sum_info();

        // 파이어볼을 이동시킵니다.
        move_fire_ball();

        // 2개 이상의 파이어볼이 1칸에 있으면 분리합니다.
        split_fire_ball();
    }

    // 3. 질량의 합을 출력합니다.
    printf("%d\n", result);
}
