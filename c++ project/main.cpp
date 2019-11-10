#include <stdio.h>

const int max_cnt = 1000001;
typedef long long lld;

int n, tree[max_cnt], max_height, result;
lld m;

int max(int a, int b){
    return a > b ? a : b;
}

lld get_tree(int val){
    lld ret = 0;
    
    for(int i=1; i<=n; i++){
        if(tree[i] > val) ret += tree[i] - val;
    }
    return ret;
}

void binary_search(int start, int end){
    
    int mid = 0;
    while(start < end){
        mid = (start + end) / 2;
        lld tree_result = get_tree(mid);
        
        if(tree_result < m){
            end = mid;
        }else{
            start = mid+1;
            result = max(result, mid);
        }
    }
}

int main(){
    scanf("%d %lld", &n, &m);
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &tree[i]);
        max_height = max(max_height, tree[i]);
    }
    
    binary_search(0, max_height);
    
    printf("%d\n", result);
}
