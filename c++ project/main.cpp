#include <iostream>
#include <queue>
#define max_int 21
#define max_val 2147483647

/*
    시간 복잡도: m * n^2
    공간 복잡도: n^2
    사용한 알고리즘: BFS - 모든 간선의 가중치가 1로 같을 때 최단거리를 계산합니다.
    사용한 자료구조: 구조체, 2차원 배열
 */

using namespace std;

int n, m, oil, person_cnt, a[max_int][max_int], start_x, start_y, person_x, person_y, target_x, target_y, check[max_int][max_int], person_dist, target_dist;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

// 좌표를 저장하기 위한 구조체
struct info{
    int x, y, dist;
};

// 연산자 오버로딩
// 1) 거리가 작은 순, 2) 행이 작은 순, 3) 열이 작은 순
bool operator < (const info &a, const info &b) {
    if (a.dist == b.dist) {
        if(a.x == b.x) {
            return a.y < b.y;
        }
        else return a.x < b.x;
    }
    else return a.dist < b.dist;
}

// 도착지점의 좌표를 2차원 배열로 저장합니다.
// x, y의 인덱스로 접근하기 위함입니다.
info target[max_int][max_int];

// bfs를 위한 배열 초기화
void init() {
    person_dist = target_dist = max_val;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            check[i][j] = -1;
        }
    }
}

// 택시의 위치에서 승객까지의 최단거리를 계산합니다.
void person_bfs() {
    
    queue<info> q;
    check[start_x][start_y] = 0;
    q.push({start_x, start_y});
    
    // 만약 시작위치에 승객이 있다면, 거리는 0으로 갱신해줍니다.
    if(a[start_x][start_y] == -1) {
        person_x = start_x;
        person_y = start_y;
        person_dist = check[start_x][start_y];
    }
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > n || nx < 1 || ny > n || ny < 1) continue;
            
            if (a[nx][ny] != 1 && check[nx][ny] == -1) {
                check[nx][ny] = check[x][y] + 1;
                
                if(a[nx][ny] == -1) {
                    info next_info = {nx, ny, check[nx][ny]};
                    info person_info = {person_x, person_y, person_dist};
                    
                    // 제일 가까운 승객을 찾아줍니다.
                    if(next_info < person_info) {
                        person_x = nx;
                        person_y = ny;
                        person_dist = check[nx][ny];
                    }
                }
                
                q.push({nx, ny});
            }
        }
    }
}

// 승객의 위치에서 도착지점까지의 최단거리를 계산합니다.
void target_bfs() {
    
    queue<info> q;
    check[person_x][person_y] = 0;
    q.push({person_x, person_y});
    
    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > n || nx < 1 || ny > n || ny < 1) continue;
            
            if (a[nx][ny] != 1 && check[nx][ny] == -1) {
                check[nx][ny] = check[x][y] + 1;
                
                // 만약 nx, ny가 도착지점이라면
                // 도착지점까지의 거리를 갱신해줍니다.
                if(nx == target_x && ny == target_y) {
                    target_dist = check[nx][ny];
                }
                
                q.push({nx, ny});
            }
        }
    }
}


int main () {
    // 1. 입력 받습니다.
    scanf("%d %d %d", &n, &m, &oil);
    
    // 1) n*n에 지도의 정보를 입력합니다.
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // 2) 출발지점의 x, y를 입력 저장합니다.
    scanf("%d %d", &start_x, &start_y);
    
    // 3) m 명의 승객 정보를 입력받습니다.
    for(int i=1; i<=m; i++) {
        scanf("%d %d %d %d", &person_x, &person_y, &target_x, &target_y);
        
        // 승객의 위치는 지도에서 -1로 표시합니다.
        a[person_x][person_y] = -1;
        
        // 승객의 도착지점을 저장합니다.
        target[person_x][person_y] = {target_x, target_y};
    }
    
    person_cnt = m;
    
    // 남은 승객의 수 만큼 반복합니다.
    while(person_cnt > 0) {
        
        // bfs를 위한 초기화
        init();
        
        // 1) 택시의 위치에서 가장 가까운 승객을 찾습니다.
        person_bfs();
        
        // 승객 까지 갈 수 없으면 종료합니다.
        if(oil <= person_dist) break;
        
        // 기름을 소모해줍니다.
        oil -= person_dist;
        
        // 승객을 태우면 지도에 표시한 -1을 지워줍니다.
        a[person_x][person_y] = 0;
        
        // 도착 지점의 정보를 갱신합니다.
        info target_info = target[person_x][person_y];
        target_x = target_info.x;
        target_y = target_info.y;
        
        // bfs를 위한 초기화
        init();
        
        // 2) 승객의 위치에서 도착지점까지의 최단 거리를 구합니다.
        target_bfs();
        
        // 도착할 수 없으면 종료합니다.
        if(oil < target_dist) break;
        
        // 소비한 만큼 기름을 채워줍니다.
        oil += target_dist;
        
        // 승객 1명을 줄여줍니다.
        person_cnt--;
        
        // 출발지점을 도착지점의 좌표로 갱신합니다.
        start_x = target_x;
        start_y = target_y;
    }
    
    // 아직 태우지 못한 승객이 있으면 -1록 갱신합니다.
    if(person_cnt > 0) oil = -1;
        
    // 출력
    printf("%d\n", oil);
}
