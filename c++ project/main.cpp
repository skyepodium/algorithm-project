#include <iostream>
#include <algorithm>
#define max_int 5000001
using namespace std;

int n, m;
int a[max_int];

int main(){

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a+n);
    printf("%d\n", a[m-1]);

}