#include <iostream>

#define max_int 201
using namespace std;

int n;
int a[max_int][max_int];
int d[max_int][max_int];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j];
        }
    }
    printf("%d\n", d[n][n]);
}