#include <iostream>
#define max_int 101
#define max_val 10001
using namespace std;

int n, m, a, b, d[max_int][max_int], result;

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        d[a][b] = d[b][a] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    for(int j=2; j<=n; j++){
        if(d[1][j] != max_val) result++;
    }
    
    printf("%d\n", result);
}
