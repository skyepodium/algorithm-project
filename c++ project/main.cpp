#include <iostream>

#define lld long long int
#define max_int 70
using namespace std;

int t;
lld d[max_int];

lld go(int i){
    if(i<=3) return d[i];
    
    if(d[i] > 0) return d[i];
        
    d[i] = go(i-1) + go(i-2) + go(i-3) + go(i-4);
    return d[i];
}

int main(){
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    
    scanf("%d", &t);
    while(t--){
        int num;
        scanf("%d", &num);
        printf("%lld\n", go(num));
    }
    
}
