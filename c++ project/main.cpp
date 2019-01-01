#include <iostream>

using namespace std;

int num;

int main(){
    scanf("%d", &num);
    int result = 1;
    for(int i=1; i<=num; i++){
        result = result * i;
    }
    printf("%d\n", result);
}
