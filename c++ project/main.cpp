#include <iostream>
#include <cstring>

#define max_int 501
using namespace std;

//시간 복잡도: O(kn^2)
//공간 복잡도: O(kn)
//사용한 알고리즘: DP Bottom-up(0/1 knapsack)
//사용한 자료구조: 2차원 배열

int t, n, m;
// d[i][j] = 탈출한 거위수가 i마리이고, 거위 숫자의 합을 n으로 나눈 나머지가 j일 때의 경우의 수
int d[101][max_int];
int mod = 1000000007;

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);

        // 1. d 배열 초기화
        memset(d, 0, sizeof(d));

        // 2. 초기값 설정
        d[0][0] = 1; //0마리가 탈출했고 합을 n으로 나눈 나머지가 0인 경우의 수는 1입니다.
        d[1][0] = 1; //1마리가 탈출했고 합을 n으로 나눈 나머지가 0인 경우의 수는 1입니다.

        // 3. 점화식 실행
        // i번째 거위부터 n-1번 거위까지 검사합니다.
        for(int i=1; i<n; i++){
            // min(n, 100)마리가 탈출 할 수 있습니다.
            for(int j=min(n, 100); j>0; j--){
                // 거위 숫자의 합을 n으로 나눌 경우 0~n-1 까지의 합을 가질 수 있습니다.
                for(int k=n-1; k>=0; k--){

                    // j마리가 탈출했고 숫자의 합을 n으로 나눈 나머지가 k일때는
                    // j-1마리가 탈출했고 숫자의 합을 나눈 나머지가 (k-i+n)%n 인 경우에서 올 수 있습니다.
                    // 원래는 i번째가 탈출했기 때문에 d[j][k] += d[j-1][k-i]라고 할 수 있지만,
                    // 나머지를 사용하기 때문에 아래와 같이 점화식이 세워집니다.
                    d[j][k] = (d[j][k] + d[j-1][(k-i+n)%n])%mod;
                }
            }
        }

        // 4. 결과 출력
        printf("%d\n", d[m][0]);
    }
}