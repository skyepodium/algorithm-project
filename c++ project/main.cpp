#include <iostream>
using namespace std;

int a, b, c, min_value, result = -1;

int main () {
    scanf("%d %d %d", &a, &b, &c);

    if (c-b > 0) {
        min_value = a / (c-b);
        
        result = min_value + 1;
    }
    
    printf("%d\n", result);
}
