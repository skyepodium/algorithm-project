#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, A[41];

void func(int pos, int end, int sum, vector<int>& vi) {
    if (pos == end) {
        vi.push_back(sum);
        return;
    }
    func(pos + 1, end, sum, vi);
    func(pos + 1, end, sum + A[pos], vi);
}

int main() {
    scanf("%d%d", &N, &S);
    for (int i = 0 ; i < N ; ++i) {
        scanf("%d", &A[i]);
    }
    vector<int> L, R;
    func(0, N / 2, 0, L);
    func(N / 2, N, 0, R);

    sort(R.begin(), R.end());
    long long ans = 0;
    for (int val : L) {
        int target = S - val;
        auto hi = upper_bound(R.begin(), R.end(), target);
        auto lo = lower_bound(R.begin(), R.end(), target);
        printf("%lld %lld\n", hi, lo);
        cout << hi - lo << endl;
        ans += hi - lo;
    }

    if (S == 0) {
        --ans;
    }
    printf("%lld\n", ans);
}
