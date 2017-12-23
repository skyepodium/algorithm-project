#include <iostream>

using namespace std;

int Rev(int num){
    
    int result = 0;
    while(num > 0){
        result = result * 10;
        result = result + num%10;
        num = num/10;
    }
    
    return result;
}

int main() {
    
    int X, Y;
    cin >> X >> Y;
    
    cout << Rev(Rev(X) + Rev(Y)) << endl;
}
