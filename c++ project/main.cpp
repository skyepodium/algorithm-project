#include <iostream>

#define max_int 21
#define max_val 210000
using namespace std;

int n;
int d[max_int][max_int];
bool unused[max_int][max_int];
int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &d[i][j]);
        }
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(i == k) continue;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(k == j) continue;

                if(d[i][j] > d[i][k] + d[k][j]){
                    printf("-1\n");
                    return 0;
                }
                
                if(d[i][j] == d[i][k] + d[k][j]){
                    unused[i][j] = true;
                }
            }
        }
    }
    
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(unused[i][j] == false){
                result += d[i][j];
            }
        }
    }
    
    printf("%d\n", result/2);
    return 0;
}
