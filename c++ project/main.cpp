#include <iostream>

using namespace std;

int t, n, m;

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d", &n, &m);
        
        int a, b;
        b = n/2;
        a = n - b*2;
        
        while(a+b < m){
            b = b-1;
            a = a+2;
        }
        
        printf("#%d %d %d\n", test_case, a, b);
    }
    
    return 0;
}
