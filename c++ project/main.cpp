#include <iostream>
#define max_int 65
#define lld long long int

using namespace std;

int t, n;
lld d[max_int][10];
lld result;

int main(){

    for(int j=0; j<=9; j++){
        d[1][j] = 1;
    }
    
    for(int i=2; i<=64; i++){
        for(int j=0; j<=9; j++){
            for(int k=j; k<=9; k++){
                d[i][j] = d[i][j] + d[i-1][k];
            }
        }
    }
    
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%d", &n);
        
        result = 0;
        for(int j=0; j<=9; j++){
            result = result + d[n][j];
        }
        
        printf("%lld\n", result);
    }
    
}
