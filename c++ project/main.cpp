#include <algorithm>

using namespace std;

int getNextRoundOrder(int num) {
    if (num % 2 == 1) num--;
    return num / 2;
}

int solution(int n, int a, int b) {
    // 1. init
    int res = 0;
    a--;
    b--;

    // 2. swap
    if (a > b) swap(a, b);

    while (a >= 0 && b >= 0) {
        res++;
        if (a % 2 == 0 && a + 1 == b) break;

        a = getNextRoundOrder(a);
        b = getNextRoundOrder(b);
    }

    return res;
}