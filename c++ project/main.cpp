#include <iostream>
#define max_int 200001
using namespace std;
 
int t, n, a[max_int], d[max_int], result;
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
 
int main () {
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++) {
        scanf("%d", &n);
        
        result = 0;
        
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            d[i] = a[i];
        }
        
        for(int i=1; i<=n; i++) {
            int next_idx = i + a[i];
            
            if(next_idx <= n) {
                d[next_idx] = max(d[next_idx], d[i] + a[next_idx]);
            }
        }
        
        for(int i=1; i<=n; i++) {
            result = max(result, d[i]);
        }
        
        printf("%d\n", result);
    }
}
