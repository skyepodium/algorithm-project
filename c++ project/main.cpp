#include <iostream>

using namespace std;

int a, res = 0;

int main() {
    while (true) {
        scanf("%d", &a);
        if (a == -1) break;
        res += a;
    }
    printf("%d\n", res);
}