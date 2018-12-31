#include <iostream>
#include <algorithm>
#define max_int 201
using namespace std;

int t, n, k;
float a[max_int];
float d[max_int][max_int];

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++){
            scanf("%f", &a[i]);
            for(int j=1; j<=k; j++){
                d[i][j] = 0;
            }
        }

        sort(a+1, a+n+1);

        d[1][1] = a[1]/2;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=k; j++){
                d[i][j] = max(d[i-1][j], (d[i-1][j-1] + a[i])/2);
            }
        }

        float result = 0;
        for(int i=1; i<=n; i++){
            result = max(result, d[i][k]);
        }
        printf("#%d %f\n", test_case, result);
    }
}