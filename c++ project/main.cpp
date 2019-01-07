#include <iostream>

#define lld long long int
#define max_int 101
using namespace std;

int n;
int a[max_int][max_int];
lld d[max_int][max_int];

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    d[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == 0) continue;

            //가로
            if(j+ a[i][j] <=n ) d[i][j + a[i][j]] += d[i][j];

            //세로
            if(i+ a[i][j] <=n ) d[i + a[i][j]][j] += d[i][j];
        }
    }

    printf("%lld\n", d[n][n]);
}