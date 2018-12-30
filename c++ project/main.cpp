#include <iostream>
#include <algorithm>
#include <vector>

#define lld long long int
#define max_int 1001
using namespace std;

int t, n, temp;
int a[max_int];
int result;

bool cal_num(int num){
    int cur = 10;
    int sub;
    while(num > 0){
        sub = num%10;
        num /= 10;
        if(cur < sub){
            return false;
            break;
        }
        cur = sub;
    }
    return true;
}

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case<=t; test_case++){
        scanf("%d", &n);
        result = -1;
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }

        sort(a, a+n, greater<int>());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                temp = a[i]*a[j];
                if(cal_num(temp)){
                    if(temp > result){
                        result = temp;
                        break;
                    }
                };
            }
        }

        printf("#%d %d\n", test_case, result);
    }
}