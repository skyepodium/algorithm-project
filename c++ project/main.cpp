#include <iostream>

#define max_val 10001

using namespace std;

//시간 복잡도: O(nlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 이분 탐색(재귀)
//사용한 자료구조: 1차원 배열


int d[max_val];
int max_cost = 0;
int n, m;
int result = 0;
int sum_cost = 0;

int max(int a, int b){
    if(a<b) return b;
    else return a;
}

int cal_cost(int mid){
    
    int ret = 0;
    
    for(int i=0; i<n; i++){
        if(d[i] < mid) ret = ret + d[i];
        else ret = ret + mid;
    }
    
    return ret;
}

void binary_search(int start, int end){
    
    if(start >= end) return;
    int mid = (start + end)/2;
    int tmp = cal_cost(mid);
    
    if(tmp <= m){
        result = mid;
        binary_search(mid+1, end);
    }else{
        binary_search(start, mid);
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
        binary_search(0, max_cost);
        printf("%d\n", result);
    }
    
}
