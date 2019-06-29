#include <iostream>
#include <algorithm>
#define lld long long int
#define max_int 1000001
using namespace std;

int t, n, a[max_int];

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        
        sort(a + 1, a + 1 + n);
        
        printf("#%d %lld\n", test_case, (lld)(a[1] * a[n]));
    }
}
