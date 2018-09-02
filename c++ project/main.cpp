#include <iostream>
#include <algorithm>

#define max_int 100000
#define max_val 1000000000
using namespace std;

int n, m;
int tree_min[max_int*4];
int tree_max[max_int*4];
int idx;
int a, b;


//5. 구간의 최소값을 계산한다.
int min_data(int start, int end){
    
    int result = max_val;
    while(start<=end){
        
        if(start%2 == 1) result = min(result, tree_min[start]);
        if(end%2 == 0) result = min(result, tree_min[end]);
        
        start = (start + 1)/2;
        end = (end - 1)/2;
    }
    return result;
}

//6. 구간의 최대값을 계산한다.
int max_data(int start, int end){
    
    int result = 0;
    while(start<=end){
        
        if(start%2 == 1) result = max(result, tree_max[start]);
        if(end%2 == 0) result = max(result, tree_max[end]);
        
        start = (start + 1)/2;
        end = (end - 1)/2;
    }
    return result;
}

int main(){
    
    scanf("%d %d", &n, &m);
    
    //1. n을 넘는 2의 제곱수를 계산한다.
    idx = 1;
    while(idx<n){
        idx = idx*2;
    }
    //트리는 1부터 시작하기 때문에 1을 빼준다.
    idx--;
    
    //2. 리프노드에 수를 입력받는다.
    for(int i=1; i<=n; i++){
        scanf("%d", &tree_min[i+idx]);
        tree_max[i+idx] = tree_min[i+idx];
    }
    
    //3. Min, Max Indexed Tree를 구성한다.
    for(int i=idx; i>=1; i--){
        tree_min[i] = min(tree_min[i*2], tree_min[i*2+1]);
        tree_max[i] = max(tree_max[i*2], tree_max[i*2+1]);
    }
    
    //4. m개의 명령을 입력받는다.
    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        
        printf("%d %d\n", min_data(a+idx, b+idx), max_data(a+idx, b+idx));
    }
    
}
