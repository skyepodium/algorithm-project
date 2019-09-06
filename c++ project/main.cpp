#include <iostream>
#define max_int 100001
#define lld long long int
using namespace std;

int n;
lld d[max_int], dist[max_int], price[max_int], min_price;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i <= n-1; i++){
        scanf("%lld", &dist[i]);
    }  
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &price[i]);
    }
    
    min_price = price[1];
    d[1] = min_price * dist[1];
    
    for(int i=2; i<=n-1; i++){
        if(price[i] < min_price) min_price = price[i];
        
        d[i] = d[i-1] + min_price * dist[i];
    }
    
    printf("%lld\n", d[n-1]);
}
