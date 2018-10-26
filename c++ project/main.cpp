#include <iostream>
#include <algorithm>

#define max_val 2147483647
#define max_int 100001

using namespace std;

int n, m, idx, a, b;
int tree[max_int*4];

int find_data(int start, int end){
    
    int result = max_val;
    
    while(start <= end){
        
        if(start%2 == 1) result = min(result, tree[start]);
        if(end%2 == 0) result = min(result, tree[end]);
        
        start = (start + 1) / 2;
        end = (end - 1) / 2;
        
    }
    
    return result;
}

int main(){
    scanf("%d %d", &n, &m);
    
    idx = 1;
    while(idx<n){
        idx = idx*2;
    }
    idx--;
    
    //리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%d", &tree[idx+i]);
    }
    
    //min_indxed_tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
    
    //쿼리를 입력받는다.
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", find_data(a+idx, b+idx));
    }
    
}
