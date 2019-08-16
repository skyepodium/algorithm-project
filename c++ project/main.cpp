#include <iostream>
#include <algorithm>
#define max_int 300001

using namespace std;

int n, q, s, e, a[max_int], d[max_int];

int main(){
    scanf("%d %d", &n, &q);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    sort(a + 1, a + 1 + n);
    
    for(int i=1; i<=n; i++){
        d[i] = d[i-1] + a[i];
    }
    
    for(int i=1; i<=q; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", d[e] - d[s-1]);
    }
    
}
