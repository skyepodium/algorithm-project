#include <iostream>
#include <string>
#include <cmath>

#define lld long long int
using namespace std;

string n;
int b;
lld result;

int main(){
    cin >> n >> b;

    result = 0;
    int size = (int)n.size();
    for(int i=size - 1; i>=0; i--){
        if(n[i] >= 65) n[i] = n[i] - 55;
        else n[i] = n[i] - 48;
        result += n[i] * pow(b, size - i - 1);
    }
    printf("%lld\n", result);
}