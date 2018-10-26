#include <iostream>

#define max_int 100001
using namespace std;

int n, m, s, e, idx;
int tree[max_int*4];

int find_data(int start, int end){
    
    int result = 0;
    
    while(start <= end){
        
        if(start%2 == 1) result += tree[start];
        if(end %2 == 0) result += tree[end];
        
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return result;
}

int main(){
    scanf("%d %d", &n, &m);
    
    idx = 1;
    while(idx < n){
        idx *= 2;
    }
    idx--;
    
    //리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%d", &tree[idx+i]);
    }
    
    //sum_index_tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    //질문을 입력받는다.
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", find_data(idx+s, idx+e));
    }
    
    
}
