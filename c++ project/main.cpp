#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define llu unsigned long long int
#define max_int 100001
using namespace std;

int t, n, x, num;
llu result;

struct info {
    int num;
    int val;
};

void solve() {
    scanf("%d %d", &n, &x);
    
    result = 0;

    queue<info> q;
    for(int i=1; i<=n; i++) {
        scanf("%d", &num);
        q.push({num, 0});
        result += num;
    }
    
    while(q.size() > 0) {
        info cur = q.front();
        int num = cur.num;
        int val = cur.val;
        q.pop();
        
        if(num % x != 0) break;
        
        int new_num = round(num / x);
        int new_val = val + 1;
        
        result += (llu)((llu)new_num * (llu)pow(x, new_val));
        q.push({new_num, new_val});
    }
    
    printf("%llu\n", result);
}

int main() {
    scanf("%d", &t);
    
    while(t--) {
        solve();
    }
}
