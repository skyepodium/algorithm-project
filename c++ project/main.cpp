#include <iostream>
#include <algorithm>
#define max_val 1000001
using namespace std;

int t, n, max_result, min_result;

int calc(int num){
    int ret = 0;
    while(num > 0){
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

void init(){
    max_result = 0;
    min_result = max_val;
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        
        init();
        
        for(int i=1; i<=10; i++){
            scanf("%d", &n);
            int temp = calc(n);
            min_result = min(min_result, temp);
            max_result = max(max_result, temp);
        }
        printf("#%d %d %d\n", test_case, max_result, min_result);
    }
}
