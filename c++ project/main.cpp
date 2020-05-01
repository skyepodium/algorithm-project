#include <iostream>
#define max_int 1000001
#define lld long long
using namespace  std;

int n, a[max_int], b, c;
lld result;

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d %d", &b, &c);

    for(int i=1; i<=n; i++){
        a[i] = a[i] - b;
        result++;

        if(a[i] > 0) result += a[i] / c;

        if(a[i] % c > 0) result++;
    }

    printf("%d\n", result);
}