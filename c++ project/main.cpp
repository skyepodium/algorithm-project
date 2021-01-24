#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    float m;
    
    cin >> n >> m;
    
    float cur = 0;
    int result = -1;
    for(int i=1; i<=n; i++) {
        float a, b;
        cin >> a >> b;
        float num = (a * b) / 100;
        cur += num;
        
        if(cur > m) {
            result = i;
            break;
        }
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    solve();
}
