#include <iostream>
#include <algorithm>

#define max_val 4000001
#define max_int 401
using namespace std;

int t, n, m, a, b, c;

int d[max_int][max_int];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d", &n, &m);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j] = max_val;
            }
        }
        
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            d[a][b] = min(c, d[a][b]);
        }
        
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        
        int result = max_val;
        for(int i=1; i<=n; i++){
            result = min(result, d[i][i]);
        }
        
        
        if(result == max_val) result = -1;
        printf("#%d %d\n", test_case, result);
        
    }
    
    return 0;
}
