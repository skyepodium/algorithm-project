#include <algorithm>
#include <iostream>
#define MAX_INT 5
#define MAX_VAL 1000000
using namespace std;

int a[MAX_INT], res = MAX_VAL;

int min(int a, int b) {
    return a < b ? a : b;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    for (int i = 0; i < MAX_INT; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + MAX_INT);

    for (int i = 0; i < MAX_INT; i++) {
        for (int j = i + 1; j < MAX_INT; j++) {
            for (int k = j + 1; k < MAX_INT; k++) {
                int t = a[j] * a[k] / gcd(a[j], a[k]);
                int r = a[i] * t / gcd(a[i], t);

                res = min(res, r);
            }
        }
    }

    printf("%d\n", res);
}