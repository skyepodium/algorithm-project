#include <iostream>
#include <algorithm>

#define max_int 101
using namespace std;

int n, k;
int w[max_int];
int v[max_int];
int d[max_int][100001];

int main(){
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++) scanf("%d %d", &w[i], &v[i]);

    if(k-w[1] >=0) d[1][k-w[1]] = v[1];
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            
            if(j+w[i] <= k) d[i][j] = max(d[i-1][j], d[i-1][j+w[i]] + v[i]);
            else d[i][j] = max(d[i-1][j], d[i][j]);
            
        }
    }
    
    int result = 0;
    for(int j=0; j<=k; j++){
        result=max(result, d[n][j]);
    }
    printf("%d\n", result);
}
