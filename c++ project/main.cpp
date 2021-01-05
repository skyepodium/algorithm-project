#include <iostream>
#define max_int 101
using namespace std;

int t, n, a[max_int][max_int], d[max_int][max_int];
bool is_end;

void go(int x, int y) {
    
    if(x >= n || y >= n) return;
    
    if(d[x][y] > 0) return;
    
    d[x][y] = 1;
    
    if(x == n-1 && y == n-1) {
        return;
    }
    
    int num = a[x][y];
    
    go(x + num, y);
    go(x, y + num);
}

void solve() {
    is_end = false;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = 0;
        }
    }
    
    go(0, 0);
    
    if(d[n-1][n-1]) {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main () {
    scanf("%d", &t);
    
    while(t--) {
        solve();
    }
}
