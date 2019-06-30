#include <iostream>
#define max_int 100001
using namespace std;

int n, a[max_int], d[max_int], top = 1;

int lower_bound(int start, int end, int val){
    int result = 0;
    
    while(start <= end){
        int mid = (start + end) / 2;
        
        if(d[mid] < val){
            start = mid + 1;
        }else{
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    d[1] = a[1];
    for(int i=2; i<=n; i++){
        if(a[i] > d[top]){
            top++;
            d[top] = a[i];
        }
        else{
            int idx = lower_bound(1, top, a[i]);
            d[idx] = a[i];
        }
    }
    printf("%d\n", n - top);
}
