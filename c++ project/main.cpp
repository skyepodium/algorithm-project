#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b){
    
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
    
}

int main() {
    
    long long int a, b, result;
    cin >> a >> b;
    result = gcd(a, b);
    
    while(result--){
        cout << 1;
    }
    cout << endl;
}

