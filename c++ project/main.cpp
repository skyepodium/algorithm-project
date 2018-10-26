#include <iostream>

#define max_int 1000001
#define lld long long int

using namespace std;

int a[max_int];
lld cnt[max_int];
int n, m;
lld sum = 0;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        a[i] %= m;
    }
    
    cnt[0] = 1;
    for(int i=0; i<n; i++){
        sum += a[i];
        sum %= m;
        cnt[sum]++;
    }

    lld ans = 0;
    for(int i=0; i<m; i++){
        ans += (cnt[i] * (cnt[i] - 1))/2;
    }
    printf("%lld\n", ans);
    
}
