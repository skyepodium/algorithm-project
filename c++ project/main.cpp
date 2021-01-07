#include <iostream>
#define lld long long int
#define max_int 1000001
using namespace std;

int n, m, k, idx, a, b, c;
lld tree[max_int *4];

void update_tree(int idx, lld delta) {
    while (idx > 0) {
        tree[idx] += delta;
        idx /= 2;
    }
}

lld find_tree(int start, int end) {
    lld result = 0;
    while (start <= end) {
        if(start % 2 == 1) result += tree[start];
        if(end % 2 == 0) result += tree[end];
        
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return result;
}

void make_tree() {
    int num = idx;
    
    while (num > 0) {
        tree[num] = tree[num * 2] + tree[num * 2 + 1];
        num--;
    }
}

void solve() {
    scanf("%d %d %d", &n, &m, &k);
//    cin >> n >> m >> k;
    
    for(idx = 1; idx<n; idx *=2);
    idx--;
    
    for(int i=1; i<=n; i++) {
        scanf("%lld", &tree[idx + i]);
//        cin >> tree[idx + i];
    }
    
    make_tree();
    
    for(int i=1; i<=m+k; i++) {
        scanf("%d %d %d", &a, &b, &c);
//        cin >> a >> b >> c;
        // update
        if(a == 1) {
            update_tree(b + idx, c - tree[idx + b]);
        }
        //print
        else{
            printf("%lld\n", find_tree(b + idx, c + idx));
//            cout << find_tree(b + idx, c + idx) << endl;
        }
    }
    
}

int main() {
//    ios_base::sync_with_stdio(0);
    
    solve();
}
