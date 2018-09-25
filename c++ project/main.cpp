#include <iostream>
#define max_int 50
using namespace std;

int t, n;
int d[max_int][max_int];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d", &n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%1d", &d[i][j]);
            }
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            
            if(i<=n/2){
                for(int j=n/2-i; j<=n/2+i; j++){
                    sum = sum + d[i][j];
                }
            }
            else{
                for(int j=n/2-(n-1-i); j<=n/2+(n-1-i); j++){
                    sum = sum + d[i][j];
                }
            }
            
        }
        
        printf("#%d %d\n", test_case, sum);
        
    }
    
    return 0;
}
