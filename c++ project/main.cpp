#include <iostream>
#include <algorithm>

#define max_int 1001

using namespace std;

int d[max_int];
int a[max_int];
int n;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        d[i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[j] < a[i]){
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        result = max(result, d[i]);
    }
    printf("%d\n", result);
}
