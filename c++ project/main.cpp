#include <iostream>
#define max_int 100001
using namespace std;

int n, a[max_int], d[max_int], result = 1;

/*
 시간 복잡도: O(n)
 공간 복잡도: O(n)
 사용한 알고리즘: DP(bottom-up)
 사용한 자료구조: 배열
 */

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    d[1] = 1;
    for(int i=2; i<=n; i++){
        if(a[i] >= a[i-1]){
            d[i] = d[i-1] + 1;
        }
        else{
            d[i] = 1;
        }
        result = max(result, d[i]);
    }

    printf("%d\n", result);
}
