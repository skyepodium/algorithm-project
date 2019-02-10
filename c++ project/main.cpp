#include <iostream>
#include <cstring>

#define max_int 501
using namespace std;

int t, n, m;
int d[max_int][max_int];
int mod = 1000000007;

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);

        memset(d, 0, sizeof(d));

        d[0][0] = 1;
        d[1][0] = 1;
        for(int i=1; i<n; i++){
            for(int j=101; j>0; j--){
                for(int k=499; k>=0; k--){
                    // 탈출했을 때
                    d[j][k] = (d[j][k] + d[j-1][(k-i+n)%n])%mod;
                }
            }
        }

        printf("%d\n", d[m][0]);
    }
}