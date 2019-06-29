#include <iostream>
#define max_int 16
#define max_val 801

using namespace std;

/*
 시간 복잡도: O(2^n * n^2) - 1600만
 공간 복잡도: O(2^n)
 사용한 알고리즘: 비트 마스킹, DP - bottom up
 사용한 자료구조: 비트셋
 */

int n, p, a[max_int][max_int], first_status, result = max_val;
int check[1 << max_int];
char c[max_int];

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    // 0. 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    scanf("%s", c);
    
    for(int i=0; i<n; i++){
        if(c[i] == 'Y'){
            first_status |= (1<<i);
        }
    }
    scanf("%d", &p);
    
    // 1. 초기화
    int num = (1 << n);
    for(int i=0; i<num; i++){
        check[i] = max_val;
    }
    check[first_status] = 0;
    
    // 2. DP 수행
    for(int k=0; k<num; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                
                if((k & (1 << i))){
                    if(k & (1<<j)) continue;
                    int next = k | (1 << j);
                    check[next] = min(check[next], check[k] + a[i][j]);
                }
            }
        }
    }
    
    // 3. 최소값 갱신
    for(int k=0; k<num; k++){
        int cnt = 0;
        for(int q=0; q<n; q++){
            if(k & (1 << q)){
                cnt++;
            }
        }
        if(cnt >= p){
            result = min(result, check[k]);
        }
    }
    
    // 4. 예외처리
    if(result == max_val) result = -1;
    
    // 5. 출력
    printf("%d\n", result);
}
