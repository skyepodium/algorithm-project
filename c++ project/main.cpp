#include <iostream>

#define max_int 401
#define max_val 4400000

using namespace std;

int n, m, a, b, c;
int d[max_int][max_int];

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = c;
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
    
    int result = max_val;
    for(int i=1; i<=n; i++){
        result = min(result, d[i][i]);
    }
    
    if(result == max_val) printf("-1\n");
    else printf("%d\n", result);
    
}
