#include <iostream>
#define max_int 1001
using namespace std;

int n, m, a, b;
int result[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        result[a]++;
        result[b]++;
    }
    
    for(int i=1; i<=n; i++){
        printf("%d\n", result[i]);
    }
    
}
