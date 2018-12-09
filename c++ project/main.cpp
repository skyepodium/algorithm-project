#include <iostream>

#define max_int 5001
using namespace std;

int t, n, a, b, p, num;
int check[max_int];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d", &n);
        for(int i=0; i<=5000; i++) check[i] = 0;
        for(int i=0; i<n; i++){
            scanf("%d %d", &a, &b);
            for(int j=a; j<=b; j++){
                check[j]++;
            }
        }
        printf("#%d ", test_case);
        scanf("%d", &p);
        for(int i=0; i<p; i++){
            scanf("%d", &num);
            printf("%d ", check[num]);
        }
        printf("\n");
        
        
        
        
    }
    
    return 0;
}

