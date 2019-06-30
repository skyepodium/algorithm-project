#include <iostream>
#define max_int 1000001
#define lld long long int
using namespace std;

int n, q, a, b, c;
lld tree[max_int], d[max_int];

void update_tree(int idx, lld delta){
    
    while(idx <= n){
        tree[idx] += delta;
        idx += idx & -idx;
    }
}

lld get_data(int idx){
    lld result = 0;
    
    while(idx > 0){
        result += tree[idx];
        idx -= (idx & -idx);
    }
    
    return result;
}

int main(){
    scanf("%d %d", &n, &q);
    
    for(int i=0; i<q; i++){
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == 1){
            lld delta = c;
            d[b] += c;
            update_tree(b, delta);
        }
        else{
            printf("%lld\n", get_data(c) - get_data(b-1));
        }
        
    }
}
