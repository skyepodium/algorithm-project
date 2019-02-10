#include <iostream>

#define max_int 1001
using namespace std;

int n;
int a[max_int];
int d[max_int];

int main(){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        d[i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        result = max(result, d[i]);
    }

    printf("%d\n", result);

}