#include <iostream>

#define lld long long int
#define max_int 1001
using namespace std;

int n, k;
lld d[max_int][max_int];
lld mod = 10007;

int main(){
    scanf("%d %d", &n, &k);

    d[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) d[i][j] = 1;
            else d[i][j] = (d[i-1][j-1] + d[i-1][j])%mod;
            d[i][j] %= mod;
        }
    }

    printf("%lld\n", d[n][k]);
}


