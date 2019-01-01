#include <iostream>

using namespace std;

int n, num, cnt=0;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num==1) continue;
        bool isPrime = true;
        for(int j=2; j*j<=num; j++){
            if(num%j==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) cnt++;
    }
    printf("%d\n", cnt);
}