#include <iostream>
#include <algorithm>

#define max_int 1000001
using namespace std;

int n;
int a[max_int];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
}