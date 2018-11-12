#include <iostream>
#include <algorithm>

#define max_int 100001

using namespace std;

int n;
int a[max_int];
int d[max_int];

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    d[0] = a[0];
    int result = d[0];
    for(int i=1; i<n; i++){
        d[i] = max(d[i-1]+a[i], a[i]);
        result = max(result, d[i]);
    }
    printf("%d\n", result);
    
}
