#include <iostream>
#include <algorithm>

#define max_int 100001
using namespace std;

int n, a[max_int], x;

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    scanf("%d", &x);
    
    sort(a + 1, a + 1 + n);

    int start = 1;
    int end = n;
    int result = 0;
    while(start < end){
        int cur = a[start] + a[end];
        if(cur > x) {
            cur -= a[end--];
        }
        else {
            if(cur == x) result++;
            cur += a[start++];
        }
    }

    printf("%d\n", result);
}