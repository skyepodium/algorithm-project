#include <iostream>
#include <algorithm>
#define max_int 100001
using namespace std;

int n, a[max_int], in_d[max_int], de_d[max_int], result1 = 1, result2 = 1;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    in_d[1] = 1;
    for(int i=2; i<=n; i++){
        if(a[i] >= a[i-1]){
            in_d[i] = in_d[i-1] + 1;
        }else{
            in_d[i] = 1;
        }
        result1 = max(result1, in_d[i]);
    }
    
    de_d[1] = 1;
    for(int i=2; i<=n; i++){
        if(a[i] <= a[i-1]){
            de_d[i] = de_d[i-1] + 1;
        }else{
            de_d[i] = 1;
        }
        result2 = max(result2, de_d[i]);
    }
    
    printf("%d\n", max(result1, result2));

}
