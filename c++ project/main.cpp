#include <iostream>
#include <algorithm>
#define max_int 301
#define max_val 2147483647
using namespace std;

int n, m, a[max_int][max_int], d[max_int][max_int];


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            d[i][j] = max_val;
         }
    }
    
    d[1][1] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x = a[i][j];
            
            for(int k=1; k<=x; k++){
                
                if(i+k <= n) d[i+k][j] = min(d[i][j] + 1, d[i+k][j]);
                if(j+k <= m) d[i][j+k] = min(d[i][j] + 1, d[i][j+k]);

            }  
        }
    }
    
    printf("%d\n", d[n][m]);
}
