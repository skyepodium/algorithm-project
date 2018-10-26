#include <iostream>
#include <algorithm>

#define lld long long int
#define max_int 1000001

using namespace std;

int n, m, k, idx, a, b, c;
lld tree[max_int*4];

void update_tree(int node, lld delta){
    
    while(node>0){
        tree[node] += delta;
        node = node/2;
    }
}

lld find_data(int start, int end){
    
    lld result = 0;
    
    while(start <= end){
        
        if(start%2 == 1) result += tree[start];
        if(end%2 == 0) result += tree[end];
        
        start = (start + 1)/2;
        end = (end - 1)/2;
        
    }
    
    return result;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    idx = 1;
    while(idx < n){
        idx *= 2;
    }
    idx--;
    
    //단말 노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%lld", &tree[idx+i]);
    }
    
    //sum_indexed_tree 를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    for(int i=0; i<m+k; i++){
        scanf("%d %d %d", &a, &b, &c);
        
        //update_tree
        if(a == 1){
            update_tree(b+idx, c-tree[idx+b]);
        }
        //find_data
        else{
            printf("%lld\n", find_data(b+idx, c+idx));
        }
        
    }
    
}
