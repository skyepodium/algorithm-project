#include <iostream>

#define max_int 2001
using namespace std;

int n, m, s, e;
int a[max_int];
int d[max_int][max_int];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i=1; i<=n; i++) d[i][i] = 1;
    
    for(int i=1; i<=n-1; i++){
        if(a[i] == a[i+1]) d[i][i+1] = 1;
    }
    
    for(int k=2; k<n; k++){
        for(int i=0; i<=n-k; i++){
            int j = i+k;
            if(a[i] == a[j] && d[i+1][j-1] == 1) d[i][j] = 1;
        }
    }
    
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s][e]);
    }
}
