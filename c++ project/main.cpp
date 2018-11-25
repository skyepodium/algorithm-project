#include <iostream>

using namespace std;

int a, b, temp;

int main(){
    scanf("%d %d", &a, &b);
    if(a > b){
        temp = a;
        a = b;
        b = a;
    }
    
    printf("%d %d\n", b-a, b);
}
