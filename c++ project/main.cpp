#include <iostream>

using namespace std;

int l, a, b, c, d, result, max_num;

int max(int a, int b){
    return a > b ? a : b;
}

int main() {
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

    if(a / c > b / d){
        result = l - a / c;
        if(a%c > 0) result--;
    }
    else{
        result = l - b / d;
        if(b%d > 0) result--;
    }

    printf("%d\n", result);
}