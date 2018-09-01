#include <iostream>
#include <algorithm>

#define max_val 10001
#define lld long long int

using namespace std;

int d[max_val];
int max_cost = 0;
int n, m;
lld sum_cost = 0;
lld result = 0;


lld cal_cost(int mid){
    
    lld ret = 0;
    
    for(int i=0; i<n; i++){
        if(d[i] < mid) ret = ret + d[i];
        else ret = ret + mid;
    }
    
    return ret;
}

void binary_search(){
    
    int start = 0;
    int end = max_cost;
    int mid = 0;
    lld tmp = 0;
    
    while(start < end){
        
        mid = (start + end)/2;
        
        tmp = cal_cost(mid);
        
        if(tmp <= m){
            result = mid;
            start = mid + 1;
        }else{
            end = mid;
        }
    }
}

int main(){
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &d[i]);
        sum_cost = sum_cost + d[i];
        max_cost = max(max_cost, d[i]);
    }
    
    scanf("%d", &m);
    
    if(sum_cost <= m){
        printf("%d\n", max_cost);
    }else{
        binary_search();
        printf("%lld\n", result);
    }
    
}
