#include <iostream>

#define max_int 1001
using namespace std;

int n;
int d[max_int];
int mod = 10007;

int main(){
    scanf("%d", &n);
    d[0] = 1;
    d[1] = 1;
    for(int i=2; i<=n; i++){
        d[i] = d[i-1]%mod + d[i-2]%mod;
        d[i] %= mod;
    }
    
    printf("%d\n", d[n]%mod);
}
