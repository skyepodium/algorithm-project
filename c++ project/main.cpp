#include <iostream>
#define max_int 41
#define lld long long int
using namespace std;

int n, m, num, a[max_int];
lld result = 1;

int main(){
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for(int i=3; i<max_int; i++){
        a[i] = a[i-1] + a[i-2];
    }
    
    scanf("%d %d", &n, &m);
    
    int cur = 1;
    for(int i=0; i<m; i++){
        scanf("%d", &num);
        result *= a[num - cur];
        cur = num + 1;
    }
    result *= a[n-cur+1];
    printf("%lld\n", result);
}
