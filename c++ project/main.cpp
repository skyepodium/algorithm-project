#include <iostream>
#include <algorithm>

#define max_int 10001
using namespace std;

int n;
int a[max_int];
int d[max_int][3];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    d[1][1] = a[1];
    for(int i=2; i<=n; i++){
        d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }

    printf("%d\n", max(d[n][0], max(d[n][1], d[n][2])));
}