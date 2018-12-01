#include <iostream>

#define max_int 101
#define lld long long int
using namespace std;

int n;
int a[max_int];
lld d[max_int][21];
int end_num;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    end_num = a[n];
    
    d[1][a[1]] = 1;
    
    for(int i=2; i<n; i++){
        for(int j=0; j<=20; j++){
            if(j+a[i] <= 20) d[i][j] += d[i-1][j+a[i]];
            
            if(j-a[i] >= 0) d[i][j] += d[i-1][j-a[i]];
        }
    }
    
    printf("%lld\n", d[n-1][end_num]);
    
}
