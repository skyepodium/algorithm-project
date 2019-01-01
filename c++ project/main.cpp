#include <iostream>
#include <algorithm>

using namespace std;

int num;
int a[2] = {5, 2};
int cnt[2];
int result = 0;

int main(){
    scanf("%d", &num);

    for(int i=1; i<=num; i++){
        int base = i;
        for(int j=0; j<2; j++){
            while(base%a[j] == 0){
                base /= a[j];
                cnt[j]++;
            }
        }
    }
    if(cnt[0] == 0 || cnt[1] == 0){
        result = 0;
    }
    else{
        result = min(cnt[0], cnt[1]);
    }


    printf("%d\n", result);
}