#include <iostream>
#define max_int 1000001
#define lld long long int

using namespace std;

lld tree[max_int*4];
int n, m, k;
int idx;
int a, b, c;

void update_tree(int node, lld delta){
    
    while(node>0){
        tree[node] = tree[node] + delta;
        node = node/2;
    }
}

lld sum_data(int start, int end){
    
    lld result = 0;
    while(start <= end){
        
        if(start%2 == 1) result = result + tree[start];
        if(end%2 == 0) result = result + tree[end];
        
        start = (start+1)/2;
        end = (end-1)/2;
    }
    
    return result;
}


int main(){
    
    scanf("%d %d %d", &n, &m, &k);
    
    //1. n을 넘는 리프노드의 최대 개수를 계산한다.
    idx = 1;
    while(idx<n){
        idx = idx*2;
    }
    //트리가 1부터 시작하기 때문에 1을 빼준다.
    idx--;
    
    //2. 리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%lld", &tree[i+idx]);
    }
    
    //3. Sum Indexed Tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    //4. m+k개의 명령을 입력받는다.
    for(int i=1; i<=m+k; i++){
        scanf("%d %d %d", &a, &b, &c);
        
        //5. 트리를 업데이트 한다.
        if(a==1){
            lld delta = c - tree[idx+b];
            update_tree(idx+b, delta);
        }
        
        //6. 구간합을 계산한다.
        else{
            printf("%lld\n", sum_data(idx+b, idx+c));
        }
    }
    
}
