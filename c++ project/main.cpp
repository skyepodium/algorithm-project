#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max_val 1000000001
#define max_int 200001
#define lld long long int
using namespace std;

int n, m, check[max_int], s_num, c_node, a[max_int], s, e;
bool idx[max_int];
vector<int> v[max_int];

lld result;

void init() {
    for(int i=1; i<=n; i++) {
        check[i] = 0;
    }
}

void dfs(int node) {
    check[node] = 1;
    if(node != c_node) {
        result = max(result, (lld)(a[node] - s_num));
    }
    
    for(int i=0; i<v[node].size(); i++) {
        int next = v[node][i];
        if(!check[next]) {
            dfs(next);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    result = (lld)(max_int * max_val) * -1;
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    for(int i=1; i<=m; i++) {
        cin >> s >> e;
        v[s].push_back(e);
        idx[s] = true;
    }
    
    for(int i=1; i<=n; i++) {
        if(idx[i]) {
            init();
            c_node = i;
            s_num = a[i];
            dfs(i);
        }
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);

    solve();
}
