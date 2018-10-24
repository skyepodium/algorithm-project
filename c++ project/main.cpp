#include <iostream>

#define max_int 100001
#define lld long long int

using namespace std;

int a[max_int];
lld d[max_int];
int n, m, s, e;

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        d[i] = a[i] + d[i-1];
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%lld\n", d[e] - d[s-1]);
    }
}
