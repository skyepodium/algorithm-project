#include <iostream>

#define max_int 1001
#define max_val 10001
using namespace std;

int n, m;
int d[max_val];
int k[max_int];
int s[max_int];

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d %d", &k[i], &s[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=m; j>=k[i]; j--){
            if(j-k[i]>=0) d[j] = max(d[j], d[j-k[i]] + s[i]);

        }
    }

    printf("%d\n", d[m]);
}