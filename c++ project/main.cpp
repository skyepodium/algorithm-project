#include <iostream>

using namespace std;

int t, n, m, num;

int main(){
    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d %d", &n, &m);

        if(n > m){
            printf("0\n");
        }
        else{
            num = m - n;

            int base = 4;
            int result = base + num;
            printf("%d\n", result);
        }
    }
}