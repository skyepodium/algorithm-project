#include <iostream>
#include <algorithm>

#define lld long long int
#define max_int 101
using namespace std;

int t, n, result;
int a[max_int][max_int];
lld d[max_int][max_int];
int p[max_int][max_int];
lld max_val;

void init() {
    max_val = 0;
    result = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = 0;
            p[i][j] = 0;
        }
    }
}

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d", &n);

        init();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                scanf("%d", &a[i][j]);
            }
        }

        d[1][1] = a[1][1];
        p[1][1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){

                if(j==1) {
                    d[i][j] = d[i-1][j] + a[i][j];
                    p[i][j] = 1;
                }
                else if(j==i) {
                    d[i][j] = d[i-1][j-1] + a[i][j];
                    p[i][j] = 1;
                }
                else {
                    if(d[i-1][j-1] > d[i-1][j]){
                        d[i][j] = d[i-1][j-1] + a[i][j];
                        p[i][j] = p[i-1][j-1];
                    }else if(d[i-1][j-1] < d[i-1][j]){
                        d[i][j] = d[i-1][j] + a[i][j];
                        p[i][j] = p[i-1][j];
                    }
                    else{
                        d[i][j] = d[i-1][j] + a[i][j];
                        p[i][j] = p[i-1][j-1] + p[i-1][j];
                    }
                }
                max_val = max(max_val, d[i][j]);
            }
        }

        for(int j=1; j<=n; j++){
            if(max_val == d[n][j]){
                result += p[n][j];
            }
        }
        printf("%d\n", result);
    }
}