#include <iostream>
#include <algorithm>

#define max_int 300
using namespace std;

int t, n;
int a[max_int][max_int];
int d[max_int][max_int];

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                a[i][j] = 0;
                d[i][j] = 0;
            }
        }
        for(int i=1; i<=2*n-1; i++){
            if(i <= n){
                for(int j=1; j<=i; j++){
                    scanf("%d", &a[i][j]);
                }
            }
            else{
                for(int j=1; j<=2*n-i; j++){
                    scanf("%d", &a[i][j]);
                }
            }
        }

        d[1][1] = a[1][1];
        for(int i=2; i<=2*n-1; i++){
            if(i <= n){
                for(int j=1; j<=i; j++){
                    if(j==1){
                        d[i][j] = d[i-1][j] + a[i][j];
                    }
                    else{
                        d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
                    }
                }
            }
            else{
                for(int j=1; j<=2*n-i; j++){
                    d[i][j] = max(d[i-1][j], d[i-1][j+1]) + a[i][j];
                }
            }
        }
        printf("%d\n", d[2*n-1][1]);
    }
}