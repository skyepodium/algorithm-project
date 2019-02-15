#include <iostream>

#define max_int 101
#define max_val 10001
using namespace std;

int n, m;
int w[max_int];
int p[max_int];
int d[max_int][max_val];

int main(){
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &w[i], &p[i]);
    }

    d[1][m] = 0;
    if(m-w[1] >= 0) d[1][m-w[1]] = p[1];

    for(int i=2; i<=n; i++){
        for(int j=0; j<=m; j++){
            d[i][j] = d[i-1][j];

            if(j+w[i] <= m) d[i][j] = max(d[i][j], d[i-1][j+w[i]] + p[i]);
        }
    }

    int result = 0;
    for(int j=0; j<=m; j++){
        result = max(result, d[n][j]);
    }
    printf("%d\n", result);
}