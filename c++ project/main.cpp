#include <iostream>
#include <cstring>
#define max_int 16

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법(Bottom-up)
//사용한 자료구조: 2차원 배열

int n, m, k;
int a[max_int][max_int];
// d[i][j]는 i, j로 올 수 있는 경우의 수
int d[max_int][max_int];

int main(){
    scanf("%d %d %d", &n, &m, &k);

    // 분기 처리
    if(k!=0) {
        // 꼭 통과해야하는 칸의 i, j
        int mid_i, mid_j;

        // 1번째 칸부터 n*m 칸 까기 차례로 채웁니다.
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                count++;
                // 현재 칸이 k번째 칸이면 mid_i, mid_j를 갱신해줍니다.
                if (count == k) {
                    mid_i = i;
                    mid_j = j;
                }
            }
        }

        // (1, 1)에서 k번째 칸 까지 점화식 수행
        d[1][1] = 1;
        for (int i = 1; i <= mid_i; i++) {
            for (int j = 1; j <= mid_j; j++) {
                if (i == 1 && j == 1) continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }

        int mid_result = d[mid_i][mid_j];

        // 초기화
        memset(d, 0, sizeof(d));

        // k번째 칸에서 n*m 번째 칸까지 점화식 수행
        d[mid_i][mid_j] = 1;
        for (int i = mid_i; i <= n; i++) {
            for (int j = mid_j; j <= m; j++) {
                if (i == mid_i && j == mid_j) continue;

                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        // 결과 출력
        printf("%d\n", mid_result * d[n][m]);
    }
    else{

        // 첫번째 칸에서 n*m 번째 칸까지 점화식 수행
        d[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        printf("%d\n", d[n][m]);
    }
}