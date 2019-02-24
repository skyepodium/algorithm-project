#include <iostream>
#include <algorithm>

#define max_int 500001
using namespace std;

int n, m, num;
int a[max_int];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a+n);

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &num);

        int up_idx = upper_bound(a, a+n, num) - lower_bound(a, a+n, num);
        printf("%d ", up_idx);
    }
    printf("\n");
}