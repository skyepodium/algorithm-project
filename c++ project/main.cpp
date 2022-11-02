#include <iostream>

using namespace std;

int n, m, k, x, l, r, res;

int abs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d", &k);

    l = 1;
    r = m;

    for (int i = 0; i < k; i++) {
        scanf("%d", &x);

        int l_delta = abs(x - l);
        int r_delta = abs(x - r);

        if (x < l) {
            l -= l_delta;
            r -= l_delta;
            res += l_delta;
        } else if (x > r) {
            l += r_delta;
            r += r_delta;
            res += r_delta;
        }
    }

    printf("%d\n", res);
}
