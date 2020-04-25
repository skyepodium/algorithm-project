#include <iostream>
#define max_int 1001
using namespace std;

int t, n, a[max_int], mulNum, result = -1;

int max(int a, int b){
    return a > b ? a: b;
}

void check(int base_num) {
    bool canUse = true;

    int num = base_num;

    int cur = (num % 10) + 1;
    while(num > 0){
        int res = num % 10;
        if(res == cur - 1) {
            num = num / 10;
            cur = res;
        } else{
            canUse = false;
            break;
        }
    }

    if(canUse) {
        result = max(result, base_num);
    }
}

int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case<=t; test_case++){

        result = -1;

        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }

        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++){
                mulNum = a[i] * a[j];
                check(mulNum);
            }
        }

        printf("#%d %d\n", test_case, result);
    }
}