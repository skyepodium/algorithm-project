#include <iostream>
#include <algorithm>

#define max_val 10000001
#define max_int 101
using namespace std;

int n, m, a, b, c;
int d[max_int][max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
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
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == max_val) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    
}
