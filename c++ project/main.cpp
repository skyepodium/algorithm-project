#include<cstdio>
#define mod (int)(1e9+7)
const int MAX_N = 4e6;
int n, k, fac[MAX_N + 1];
typedef long long ll;
int f(int x, int y) {
    if (!y) return 1;
    int t = f(x, y / 2);
    return (ll)t*t%mod*(y & 1 ? x : 1) % mod;
}
int main() {
    scanf("%d %d", &n, &k);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i%mod;
    printf("%lld", (ll)fac[n] * f(fac[n - k], mod - 2) % mod*f(fac[k], mod - 2) % mod);
    return 0;
}
