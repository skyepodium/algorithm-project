#include <iostream>
#include <algorithm>
#define max_int 1001
#define max_val 100000001
using namespace std;

int n, m, a[max_int][max_int], d[max_int][max_int][3];

int max3(int a, int b, int c){
    return max(max(a, b), c);
}

void init(){
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            d[i][j][0] = -max_val;
            d[i][j][1] = -max_val;
            d[i][j][2] = -max_val;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    init();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    /*
     0 위
     1 왼쪽
     2 오른쪽
    */
    d[1][1][0] = a[1][1];
    d[1][1][1] = a[1][1];
    d[1][1][2] = a[1][1];
    
    for(int j=2; j<=m; j++){
        d[1][j][2] = d[1][j-1][2] + a[1][j];
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t = max3(d[i-1][j][0], d[i-1][j][1], d[i-1][j][2]);
            int l = max(d[i][j-1][0], d[i][j-1][1]);
            
            if(t < l){
                d[i][j][1] = max(d[i][j][1], l + a[i][j]);
            }else{
                d[i][j][0] = max(d[i][j][0], t + a[i][j]);
            }
        }
        
        for(int j=m; j>=1; j--){
            
            int t = max3(d[i-1][j][0], d[i-1][j][1], d[i-1][j][2]);
            int r = max(d[i][j+1][0], d[i][j+1][2]);
            
            if(t < r){
                d[i][j][2] = max(d[i][j][2], r + a[i][j]);
            }else{
                d[i][j][0] = max(d[i][j][0], t + a[i][j]);
            }
        }
    }
    
    printf("%d\n", max3(d[n][m][0], d[n][m][1], d[n][m][2]));
}
