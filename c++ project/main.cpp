#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int x, s, res;
priority_queue<int, vector<int>, cmp> pq;

int main() {
    // 1. input
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;

    // 2. loop
    s = 64;
    pq.push(s);

    while (!pq.empty() && s > x) {
        int cur = pq.top();
        s -= cur;
        int half = cur / 2;
        pq.pop();

        if (half == 0) continue;

        if (s + half > x) {
            pq.push(half);
            s += half;
        } else {
            pq.push(half);
            pq.push(half);
            s += cur;
        }
    }

    while (!pq.empty()) {
        if (pq.top() != 0) res++;
        pq.pop();
    }

    cout << res << endl;
}