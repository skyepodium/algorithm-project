#include <stdio.h>

/*
시간 복잡도: O(n)
공간 복잡도: O(n)
사용한 알고리즘: 동적 계획법(bottom-up, tabulation)
사용한 자료구조: 1차원 배열
*/

const int max_int = 17;

/*
 d[i]는 i번째 날에 받을 수 있는 최대 금액
 1) i번째 날에 일을 했을 경우
 d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
 
 2) i번째 날에 일을 하지 않았을 경우
 d[i+1] = max(d[i+1], d[i]);
 */
int n, t[max_int], p[max_int], d[max_int], result;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    //1. 문제 입력
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    
    // 2. DP 수행
    for(int i=1; i<=n; i++){
        // 1) i번째 날에 일을 했을 경우
        if(i+t[i] <=n+1){
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
            // 최대값 갱신
            result = max(result, d[i+t[i]]);
        }
        
        // 2) i번째 날에 일을 하지 않았을 경우
        d[i+1] = max(d[i+1], d[i]);
        // 최대값 갱신
        result = max(result, d[i+1]);
    }

    // 3. 출력
    printf("%d\n", result);
}
