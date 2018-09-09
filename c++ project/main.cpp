#include <iostream>
#include <cstring>
#define max_int 101

using namespace std;

bool check[max_int];
int n, k, num;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(check, false, sizeof(check));
        scanf("%d %d", &n, &k);
        
        for(int i=0; i<k; i++){
            scanf("%d", &num);
            check[num] = true;
        }
        
        printf("#%d ", test_case);
        for(int i=1; i<=n; i++){
            if(check[i] == false){
                printf("%d ", i);
            }
        }
        printf("\n");
        
    }
    return 0;
}
