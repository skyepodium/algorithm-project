#include <iostream>
#include <algorithm>

#define max_int 1000001
using namespace std;

int n;
int d[max_int];

int go(int i){
    
    if(i < 4) return d[i];
    
    if(d[i] > 0) return d[i];
    d[i] = n;
    if(i%3 == 0) d[i] = min(d[i], go(i/3) + 1);
    if(i%2 == 0) d[i] = min(d[i], go(i/2) + 1);
    
    d[i] = min(d[i], go(i-1) + 1);
    
    return d[i];
}

int main(){
    scanf("%d", &n);
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    
    printf("%d\n", go(n));
}
