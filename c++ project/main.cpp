#include <iostream>
#include <algorithm>

#define max_int 100001
using namespace std;

int n, s;
int a[max_int];
int result;

int main(){
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    
    int left = 0;
    int right = 0;
    int cur = a[0];
    result = n+1;
    
    while(left < n && right < n){
        
        if(cur < s){
            right++;
            if(right < n) cur += a[right];
        }
        else if(cur > s){
            result = min(result, right-left+1);
            cur -= a[left];
            left++;
        }
        else{
            result = min(result, right-left+1);
            right++;
            if(right < n) cur += a[right];
        }
        
    }
    
    if(result > n) printf("0\n");
    else printf("%d\n", result);
}
