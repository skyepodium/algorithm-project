#include <iostream>

#define max_int 31
using namespace std;

int n, k;
int d[31][31];

int main(){
    
    d[0][0] = 1;
    for(int i=1; i<31; i++){
        for(int j=0; j<31; j++){
            if(j==0) d[i][j] = 1;
            else d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }
    scanf("%d %d", &n, &k);
    printf("%d\n", d[n-1][k-1]);
}
