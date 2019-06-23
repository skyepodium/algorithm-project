#include <iostream>
#define max_int 101
using namespace std;

int n, m, a[max_int], s, e;

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) a[i] = i;
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        swap(a[s], a[e]);
    }
    
    for(int i=1; i<=n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
