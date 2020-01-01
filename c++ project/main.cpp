#include <iostream>
#define max_int 101
using namespace std;

int n, m, a[max_int], result, sum_result;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    
    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            for(int k=j+1; k<=n; k++){
                sum_result = a[i] + a[j] + a[k];
                if(sum_result <= m){
                    result = max(result, sum_result);
                }
            }
        }
    }
    printf("%d\n", result);
}
