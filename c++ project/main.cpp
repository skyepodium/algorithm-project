#include <iostream>
using namespace std;

int t;
double d, l, n, result;

void solve(int t) {
    scanf("%lf %lf %lf", &d, &l, &n);

    result = 0;
    
    for(int i=0; i<=n-1; i++) {
        result += d * (1 + i * (l/100));
    }
    
    printf("#%d %d\n", t, (int)result);
}
    

int main() {
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++) {
        solve(test_case);
    }
}
