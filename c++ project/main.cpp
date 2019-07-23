#include <iostream>
#define max_int 16

using namespace std;

/*
 시간 복잡도: O(n^2)
 공간 복잡도: O(n)
 사용한 알고리즘: 동적 계획법(bottom-up, tabulation)
 사용한 자료구조: 배열
 */

/*
 t는 일을 완료하는데 걸리는 기간
 p는 일을 완료하고 받을 수 있는 금액
 
 d[n]은 n+1에 받을 수 있는 최대 금액을 의미합니다.
 아래의 예시에서 1일에 일을 하면 3일동안 일을 하기 때문에 4일에 금액을 받습니다.
   1  2  3  4
 t 3  5  1  1
 p 10 20 10 20
 d 0  0  0  10
 */
int n, t[max_int], p[max_int], d[max_int], result;

// 두수 a, b에서 최대값을 구하는 함수 (삼항 연산자 사용)
int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    // 1. 입력
    scanf("%d", &n);
    
    
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    
    
    // 2. DP (bottom-up) 수행
    for(int i=1; i<=n + 1; i++){
        for(int j=1; j<i; j++){
            // 1) j 번째 날에서 일을 안하고 i 번째 날까지 온 경우(j < i)
            d[i] = max(d[i], d[j]);
            
            // 2) j 번째 날에서 t[j] 기간 동안 일을하고 보상을 p[j] 받은 경우
            // 그 보상은 j + t[j] 날 받습니다.
            if(j + t[j] == i){
                d[i] = max(d[i], d[j] + p[j]);
            }
        }
        
        // 3) 최대값을 갱신해줍니다.
        result = max(result, d[i]);
    }
    
    // 3. 출력
    printf("%d\n", result);
}
