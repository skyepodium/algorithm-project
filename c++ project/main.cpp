#include <iostream>

using namespace std;

int t, n, q, l, r;
int d[1001];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        for(int i=0; i<=n; i++) d[i] = 0;
        
        scanf("%d %d", &n, &q);
        for(int i=1; i<=q; i++){
            scanf("%d %d", &l, &r);
            for(int j=l; j<=r; j++){
                d[j] = i;
            }
        }
        
        printf("#%d ", test_case);
        for(int i=1; i<=n; i++) printf("%d ", d[i]);
        printf("\n");
        
        
    }
    
    return 0;
}

