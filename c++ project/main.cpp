#include <iostream>
#include <algorithm>

#define max_int 21
#define health 101
using namespace std;

int n;
int d[max_int][health];
int h[max_int];
int p[max_int];

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", &h[i]);
    for(int i=1; i<=n; i++) scanf("%d", &p[i]);

    d[1][100 - h[1]] = p[1];
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=100; j++){
            
            if(100 - h[i] >= j){
                d[i][j] = max(d[i-1][j], d[i-1][j+h[i]] + p[i]);
            }
            else{
                d[i][j] = max(d[i-1][j], d[i][j]);
            }
            
        }
    }
    
    int result = 0;
    for(int j=1; j<=100; j++){
        result = max(result, d[n][j]);
    }
    printf("%d\n", result);
    
}
