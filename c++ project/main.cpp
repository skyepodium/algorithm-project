#include <iostream>

using namespace std;

int n, a, b, result = 0;

int main(){
    scanf("%d", &n);
    

    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        result += b%a;
    }
    printf("%d\n", result);
}
