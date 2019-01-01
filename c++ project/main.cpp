#include <iostream>

#define max_int 100001
#define lld long long int
using namespace std;

int t, n, m, idx, a, b, c;
lld tree[max_int*4];

void init(){
    for(int i=0; i<=n*4; i++){
        tree[i] = 0;
    }
}

void update_tree(int node, int data){
    while(node>=1){
        tree[node] += data;
        node /= 2;
    }
}

lld sum_data(int start, int end){
    lld ret = 0;
    while(start <= end){
        if(start%2==1) ret += tree[start];
        if(end%2==0) ret += tree[end];

        start = (start + 1)/2;
        end = (end - 1)/2;
    }
    return ret;
}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);

        init();

        //1. find idx;
        for(idx = 1; idx<n; idx=idx*2);
        idx--;

        //2. insert data to leafnode
        for(int i=1; i<=n; i++){
            scanf("%lld", &tree[idx+i]);
        }

        //3. create_index_tree
        for(int i=idx; i>=1; i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }

        //4. commands
        printf("#%d ", test_case);
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);

            //4-1 update_data
            if(a == 1){
                update_tree(b+idx, c);
            }
            //4-2 sum_data
            else{
                printf("%lld ", sum_data(b+idx, c+idx));
            }
        }
        printf("\n");
    }
}