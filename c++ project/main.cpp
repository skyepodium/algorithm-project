#include <iostream>
#define max_int 1000000
#define lld long long int

using namespace std;

lld tree[max_int*4];

int n, m, k;
int a, b, c;
int idx;

//5. 인덱스 트리를 업데이트 한다.
void update_tree(int node, lld delta){
    
    //노드가 1일때도 넣어야하기 때문에 0보다 크다로 설정한다.
    while(node > 0){
        tree[node] = tree[node] + delta;
        node = node/2;
    }
}

//6. 인덱스 트리에서 구간합을 계산한다.
lld sum_data(int start, int end){
    
    lld result = 0;
    
    while(start <= end){
        
        if(start%2 == 1) result = result + tree[start];
        if(end%2 == 0) result = result + tree[end];
        
        start = (start + 1)/2;
        end = (end - 1)/2;
    }
    return result;
}


int main(){
    
    scanf("%d %d %d", &n, &m, &k);
    
    //1. n을 넘는 최소의 리프노드 수 2^n를 찾는다.
    idx = 1;
    while(idx<n){
        idx = idx*2;
    }
    //1부터 시작, 1을 빼준다.
    idx--;

    //2. 리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%lld", &tree[idx+i]);
    }
    
    //3. sum_indexed tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    //4. m+k개의 명령을 입력받는다.
    for(int i=1; i<=m+k; i++){
        scanf("%d %d %d", &a, &b, &c);

        //5. 인덱스 트리를 업데이트한다.
        if(a == 1){
        
            lld delta = c - tree[idx+b];
            update_tree(idx+b, delta);
        }
        //6. 구간합을 출력한다.
        else{
            printf("%lld\n", sum_data(idx+b, idx+c));
        }
    }
}


