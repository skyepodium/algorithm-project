#include <iostream>
#define max_int 100001
#define lld long long int
using namespace std;

int n, q, x, y, a, b;
lld tree[max_int], d[max_int];

void update_tree(int idx, lld delta){
    
    while(idx <= n){
        tree[idx] += delta;
        idx += (idx & -idx);
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

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    scanf("%d %d", &n, &q);
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &d[i]);
        update_tree(i, d[i]);
    }
 
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d", &x, &y, &a, &b);
        
        if(x > y) swap(x, y);
        printf("%lld\n", get_data(y) - get_data(x - 1));
        
        lld delta = b - d[a];
        d[a] = b;
        update_tree(a, delta);
    }
}
