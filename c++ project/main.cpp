#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define lld long long int
using namespace std;

lld n;
lld a[1000001];

int main(){
    scanf("%lld", &n);

    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }

    sort(a, a+n);

    lld result = a[0];
    lld max_cnt = 1;
    lld cur_cnt = 1;
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1]){
            cur_cnt = 1;
        }
        else{
            cur_cnt++;
        }
        if(cur_cnt > max_cnt){
            max_cnt = cur_cnt;
            result = a[i];
        }
    }


    printf("%lld\n", result);
}