#include <iostream>
#include <algorithm>
#include <cmath>
#define max_int 2048
using namespace std;

int t, n, size, a[max_int], b[max_int], result;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        result = 0;
        
        size = pow(2, n);
        
        for(int i=1; i<=size; i++){
            scanf("%d", &a[i]);
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=size; j=j+2){
                if(i%2 == 1) result += abs(a[j] - a[j+1]);
                else result += abs(b[j] - b[j+1]);
                if(i%2 == 1){
                    if(a[j] > a[j+1]) b[(j+1)/2] = a[j];
                    else b[(j+1)/2] = a[j+1];
                }
                else{
                    if(b[j] > b[j+1]) a[(j+1)/2] = b[j];
                    else a[(j+1)/2] = b[j+1];
                }
            }
            size /= 2;
        }
        
        printf("#%d %d\n", test_case, result);
    }
}
