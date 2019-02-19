#include <iostream>
#include <math.h>
#include <queue>


#define max_int 1001
using namespace std;

int n, max_val = 0;
char a[max_int];
double d[max_int];

    int main(){
    scanf("%s", a);
    n = strlen(a);

    for(int i=0; i<=n; i++){
        d[i] = sqrt(n);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            for(int k=j; k<=i; k++){
                if(a[k] == '.') continue;

                d[j+1] = min(d[j+1], sqrt(j+1));
                d[i-k+1] = min(d[i-k+1], sqrt(i-k+1));
                d[i+1] = min(d[i+1], d[j+1] + d[i-k+1]);

            }
        }
    }

    cout << d[n] << endl;
}