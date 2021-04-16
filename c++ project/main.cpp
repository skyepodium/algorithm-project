#include <iostream>
#define max_int 501
using namespace  std;

/*
    시간 복잡도: O(n^2)
    공간 복잡도: O(n^2)
    사용한 알고리즘: 백트래킹 (DFS)
    사용한 자료구조: 2차원 배열
 */

// a는 지도 정보를 저장할 2차원 배열
int n, m, a[max_int][max_int], result;
bool check[max_int][max_int];

// dx, dy는 인접한 4방향을 나타내는 방향벡터
// 0, 1, 2, 3 순서대로 왼쪽, 오른쪽, 아래쪽, 위쪽
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};


/*
    ex, ey는 ㅜ 모양의 4가지 회전 방향일때 정보를 저장합니다.
    만약 각각 분리했으면 바로 아래 주석 부분과 같습니다. (ㅜ, ㅏ, ㅗ, ㅓ)
 */
int ex[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int ey[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};

/*
    // ㅜ
    int ex_1_x[] = {0, 0, 0, 1}, ex_1_y[] = {0, 1, 2, 1};

    // ㅏ
    int ex_2_x[] = {0, 1, 2, 1}, ex_2_y[] = {0, 0, 0, 1};

    // ㅗ
    int ex_3_x[] = {0, 0, 0, -1}, ex_3_y[] = {0, 1, 2, 1};

    // ㅓ
    int ex_4_x[] = {0, -1, 0, 1}, ex_4_y[] = {0, 1, 1, 1};
 */


int max(int a, int b){
    return a > b ? a : b;
}

// DFS 로 4가지 모양 검사 (ㅜ 제외)
void dfs(int x, int y, int sum_value, int length){
    // 길이가 4 이상이면 종료햅줍니다.
    if(length >= 4){
        result = max(result, sum_value);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도 넘어가는 경우 검사
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

        // 방문하지 않은 점이면
        if(!check[nx][ny]) {

            // 들어가기전 체크해주고
            check[nx][ny] = true;

            dfs(nx, ny, sum_value + a[nx][ny], length + 1);

            // 나올때 체크를 해제합니다.
            check[nx][ny] = false;
        }
    }
}


// ㅜ 모양 검사
void check_exshape(int x, int y){

    for(int i=0; i<4; i++){

        bool isOut = false;
        int sum_value = 0;

        for(int j=0; j<4; j++){
            int nx = x + ex[i][j];
            int ny = y + ey[i][j];

            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                isOut = true;
                break;
            }
            else {
                sum_value += a[nx][ny];
            }
        }
        if(!isOut) {
            result = max(result, sum_value);
        }
    }
    // 만약 배열로 정보 저장 안해놓았으면 아래처럼 작성할 수 있습니다.

//    int sum_value = 0;
//    // 1. ㅜ
//    if(x>=1 && x+1<=n && y>=1 && y+2<=m){
//        sum_value = a[x][y] + a[x][y+1] + a[x][y+2] + a[x+1][y+1];
//        result = max(result, sum_value);
//    }
//
//    // 2. ㅏ
//    if(x >= 1 && x+2 <=n && y>=1 && y+1<=m){
//        sum_value = a[x][y] + a[x+1][y] + a[x+2][y] + a[x+1][y+1];
//        result = max(result, sum_value);
//    }
//
//    // 3. ㅗ
//    if(x-1 >= 1&& x <=n && y >=1 && y+2 <=m){
//        sum_value = a[x][y] + a[x][y+1] + a[x][y+2] + a[x-1][y+1];
//        result = max(result, sum_value);
//    }
//
//    // 4. ㅓ
//    if(x-1 >= 1 && x+1 <=n && y >=1 && y+1 <=m){
//        sum_value = a[x][y] + a[x][y+1] + a[x-1][y+1] + a[x+1][y+1];
//        result = max(result, sum_value);
//    }
}


int main(){

    // 1. 입력
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }


    // 2. 2차원 배열 각각의 원소에서 검사를 수행합니다.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // 1) DFS 로 검사

            // 방문했던 점을 또 방문해야하기 때문에
            // 들어가기전 체크를 해주고, 끝났을때 체크를 해제해줍니다.
            check[i][j] = true;
            dfs(i, j, a[i][j], 1);

            // 체크를 해제하면 무한루프에 들어가 않을까 걱정할 수 있습니다.
            // 길이로 재귀를 중단시키기 때문에, 수행횟수는 4 * 3 * 3, 한점에서 최대 36번 수행됩니다.
            check[i][j] = false;

            // 2) ㅏ 모양 검사
            check_exshape(i, j);
        }
    }


    // 3. 출력
    printf("%d\n", result);
}
