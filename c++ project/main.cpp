#include <iostream>
#include <algorithm>
#include <queue>
#define lld long long int
#define max_int 100001
#define max_val 1000000001
using namespace std;

int t, n, x, num, idx, a[max_int], last_idx;
lld result, sum_value;

void cal_idx(int num, int id) {
    
    int i=0;
    while(num > 0) {
        if(num % x != 0) break;
        num /= x;
        i++;
    }
    i++;
    
    if(idx > i) {
        idx = i;
        last_idx = id;
    }
}

void solve() {
    cin >> n >> x;
    
    sum_value = result = 0;
    last_idx = n;
    
    for(idx = 1; pow(x, idx) <= max_val; idx++);
    idx--;

    for(int i=1; i<=n; i++) {
        cin >> num;
        a[i] = num;
        sum_value += num;
        cal_idx(num, i);
    }
    
    if(idx != 1) {
        result = sum_value * idx;
    }
    else {
        result = sum_value;
    }
    
    for(int i=1; i<=n; i++) {
        if(i == last_idx) break;
        result += a[i];
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    
    while(t--) {
        solve();
    }
}
