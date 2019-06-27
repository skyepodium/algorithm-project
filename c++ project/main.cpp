#include <iostream>
#include <algorithm>
#define max_int 501
#define max_val 2147483647
using namespace std;

int n, d[max_int][max_int];
struct info{
    int a;
    int b;
};

info a[max_int];

int go(int start, int end){
    
    if(d[start][end] != max_val) return d[start][end];
    if(end == start+1) return d[start][end] = a[start].a*a[start].b*a[end].b;
    
    for(int i=start; i<end; i++){
        d[start][end] = min(d[start][end], go(start, i) + go(i+1, end) + a[start].a*a[i].b*a[end].b);
    }
    
    return d[start][end];
}

void init(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = max_val;
        }
    }
}

int main(){
    scanf("%d", &n);
    
    init();
    
    for(int i=1; i<=n; i++){
        scanf("%d %d", &a[i].a, &a[i].b);
    }
    
    printf("%d\n", go(1, n));
    
}
