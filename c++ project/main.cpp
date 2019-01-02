#include <iostream>

#define lld long long int
#define max_int 101
using namespace std;

int t, n;
int a[max_int];
lld d[max_int][21];
lld mod = 1234567891;

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case <=t; test_case++){
            scanf("%d", &n);

            for(int i=0; i<=n; i++){
                for(int j=0; j<21; j++){
                    d[i][j] = 0;
                }
            }
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }

            d[0][a[0]] = 1;
            for(int i=1; i<n-1; i++){
                for(int j=0; j<21; j++){
                    if(j-a[i] >=0) d[i][j] = (d[i][j] + d[i-1][j-a[i]])%mod;
                    if(j+a[i] <21) d[i][j] = (d[i][j] + d[i-1][j+a[i]])%mod;
                }
            }

            printf("#%d %lld\n", test_case, d[n-2][a[n-1]]);

    }


}