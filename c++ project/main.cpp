#include <iostream>
#define max_int 1001
using namespace std;

char a[max_int];

int main(){
    scanf("%s", a);
    if(a[0] >= 97) a[0] -= 32;
    printf("%s\n", a);   
}
