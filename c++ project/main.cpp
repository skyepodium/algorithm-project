#include <iostream>

#define max_int 501
using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, Top-down
//사용한 자료구조: 2차원 배열

int n, result = 0;
int a[max_int][max_int];
// d[i][j]는 i, j에서 시작해서 가장 오래 살아남을 수 있는 일 수
int d[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int go(int x, int y){
    // 메모이제이션 수행
    if(d[x][y] > 1) return d[x][y];

    // 4방향 검사
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=1 && nx<=n && ny>=1 && ny<=n){
            if(a[nx][ny] > a[x][y]){
                d[x][y] = max(d[x][y], go(nx, ny) + 1);
            }
        }
    }
    return d[x][y];
}

int main(){
    scanf("%d", &n);

    // 1. 지도 정보를 입력받습니다.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            d[i][j] = 1;
        }
    }

    // 2. 각 지점에 대한
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            result = max(result, go(i, j));
        }
    }
    printf("%d\n", result);
}