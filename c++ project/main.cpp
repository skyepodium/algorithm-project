#include <iostream>
#include <algorithm>

#define max_int 100001
#define max_val 2147483647

using namespace std;

int n, m, s, e;
int idx;
int tree[max_int*4];

int find_data(int start, int end){
    
    int result = max_val;
    
    while(start <= end){
        
        if(start%2 == 1) result = min(result, tree[start]);
        if(end%2 == 0) result = min(result, tree[end]);
        
        start = (start + 1)/2;
        end = (end - 1)/2;
        
    }
    
    
    return result;
}

int main(){
    scanf("%d %d", &n, &m);
    
    //1. n을 넘는 2의 제곱수를 구한다.
    idx=1;
    while(idx<n){
        idx = idx*2;
    }
    idx--;
    
    //2. 리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%d", &tree[i+idx]);
    }
    
    //3. min_index 트리를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
    
    //4. 질문을 입력받는다.
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", find_data(s+idx, e+idx));
    }
    
}
