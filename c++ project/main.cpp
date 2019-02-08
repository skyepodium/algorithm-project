#include <iostream>

#define max_int 101
using namespace std;

int t, n;
int mod = 1000000007;
int d[max_int];

int main(){
    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d", &n);

        d[0] = d[1] = 1;
        for(int i=2; i<=n; i++){
            d[i] = (d[i-1] + d[i-2])%mod;
        }
        printf("%d\n", d[n]);

    }
}