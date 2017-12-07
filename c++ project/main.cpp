#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main() {

    int a, b;
    cin >> a >> b;
    
    if(b>a){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    
    cout << gcd(a, b) << endl;
    cout << (a*b)/gcd(a, b) <<endl;
}

