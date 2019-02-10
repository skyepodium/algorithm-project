#include <iostream>
#include <algorithm>

#define max_int 101
#define max_val 1001
using namespace std;

int n;
int a[max_int][max_int];
int d[max_int][max_int];

void init(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = max_val;
        }
    }
}

int main(){
    scanf("%d", &n);

    init();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    d[1][1] = a[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 && j==1) continue;
            d[i][j] = min(d[i-1][j], d[i][j-1]) + a[i][j];
        }
    }

    printf("%d\n", d[n][n]);
}