#include <iostream>
#define max_int 1000001

using namespace std;

int t;
int d, a, b, cnt;
int check[max_int];

int main(int argc, char** argv)
{
    scanf("%d", &t);
    
    check[1] = true;
    for(int i=2; i*i<=max_int; i++){
        for(int j=i*i; j<=max_int; j=j+i){
            check[j] = true;
        }
    }

    for(int test_case = 1; test_case <= t; ++test_case)
    {
        scanf("%d %d %d", &d, &a, &b);
        
        cnt = 0;
        for(int i=a; i<=b; i++){
            if(check[i] == false){
                int num = i;
                while(num>0){
                    if(num%10 == d){
                        cnt++;
                        break;
                    }
                    num = num/10;
                }
            }
        }
        
        printf("#%d %d\n", test_case, cnt);
        
    }
    
    return 0;
}

