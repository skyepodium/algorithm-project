#include <iostream>
#include <algorithm>

#define max_int 1001
using namespace std;

int n;
int a[max_int];
int d[max_int][3];

int max3(int q, int w, int e){
    return max(max(q, w), e);
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    d[0][1] = a[0];

    for(int i=1; i<n; i++){
        d[i][0] = max3(d[i-1][0], d[i-1][1], d[i-1][2]);
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }


    printf("%d\n", max3(d[n-1][0], d[n-1][1], d[n-1][2]));


}