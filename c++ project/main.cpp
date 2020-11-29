#include <iostream>
#include <string>
#define lld long long int
using namespace std;

lld n;
int num, word_size;
string result;

int main () {
    scanf("%lld", &n);
    
    while(n>0) {
        num = n % 2;
        if(num == 0 ) result += "0";
        else result += "1";
        
        n = n / 2;
    }
    
    word_size = (int)result. size();
    for(int i= word_size - 1; i>=0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}
