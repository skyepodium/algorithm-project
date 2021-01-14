#include <iostream>
#include <algorithm>
#define max_int 10001
using namespace std;

int n, a[max_int], result, first, second;

int main() {
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a+1, a+1+n, less<int>());
    
    for(int i=1; i<=n; ) {
        
        if(i+1 <= n) {
            first = a[i];
            second = a[i+1];
             
            if(first * second > first + second) {
                result += (first * second);
                i = i + 2;
            }
            else {
                result += a[i];
                i = i + 1;
            }
        }
        else {
            result += a[i];
            i++;
        }
    }
    
    printf("%d\n", result);
}
