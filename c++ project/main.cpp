#include <iostream>

#define max_int 1000001
using namespace std;

int n, num;
bool a[max_int];
bool b[max_int];
int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num >=0){
            a[num] = true;
        }
        else{
            num *= -1;
            b[num] = true;
        }
    }
    for(int i=max_int-1; i>=0; i--){
        if(a[i]) printf("%d\n", i);
    }
    for(int i=1; i<=max_int-1; i++){
        if(b[i]) printf("%d\n", i*-1);
    }

}