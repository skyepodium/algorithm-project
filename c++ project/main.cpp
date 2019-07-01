#include <iostream>
#define max_int 100001
using namespace std;

int n, m, q, w, a[max_int], d[max_int];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i=1; i<=n; i++){
        d[i] = d[i-1] + a[i];
    }
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &q, &w);
        printf("%d\n", d[w] - d[q-1]);
    }
}
