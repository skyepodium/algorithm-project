#include <iostream>
#define max_int 2000000
#define lld long long int

using namespace std;

lld tree[max_int*4];
int n, m, k;
int idx;
int a, b, c;
int mod = 1000000007;

void init(){
    
    for(int i=0;i<=max_int; i++) tree[i] = 1;
}

void update_tree(int node, lld son, lld mom){
    
    while(node>0){
        
        if(tree[node] == 0){
            tree[node] = (tree[node*2]%mod * tree[node*2+1]%mod)%mod;
            tree[node] = tree[node]%mod;
        }
        else{
            tree[node] = ((tree[node]/3)*(mom))%mod;
            tree[node] = tree[node]%mod;
        }

        node = node/2;
    }
}

lld mul_data(int start, int end){
    
    lld result = 1;
    while(start <= end){
        
        if(start%2 == 1){
            result = (result%mod * tree[start]%mod)%mod;
            result = result%mod;
        }
        if(end%2 == 0){
            result = (result%mod * tree[end]%mod)%mod;
            result = result%mod;
        }
        
        start = (start+1)/2;
        end = (end-1)/2;
    }
    
    return result%mod;
}


int main(){
    
    scanf("%d %d %d", &n, &m, &k);
    
    //0. 트리를 모두 1로 초기화한다.
    init();
    
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
    
    //3. Mul Indexed Tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree[i] = (tree[i*2]%mod * tree[i*2+1]%mod)%mod;
        tree[i] = tree[i]%mod;
    }
    
    //4. m+k개의 명령을 입력받는다.
    for(int i=1; i<=m+k; i++){
        scanf("%d %d %d", &a, &b, &c);
        
        //5. 트리를 업데이트 한다.
        if(a==1){
            if(tree[idx+b] == 0){
                tree[(idx+b)*2] = (lld)c%mod;
            }
            update_tree(idx+b, tree[idx+b], (lld)c);
        }
        
        //6. 구간합을 계산한다.
        else{
            printf("%lld\n", mul_data(idx+b, idx+c)%mod);
        }
    }
    
}
