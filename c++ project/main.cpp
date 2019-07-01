#include <iostream>
#define max_int 1001
#define max_val 1000001
using namespace std;

int t, n, a[max_int], d[max_int], result;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        result = -max_val;
        
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            d[i] = 0;
        }
        
        for(int i=1; i<=n; i++){
            d[i] = d[i-1] + a[i];
        }
        
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                result = max(result, d[j] - d[i-1]);
            }
        }
        printf("%d\n", result);
    }
}
