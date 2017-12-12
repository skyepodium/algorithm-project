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

    int n;
    cin >> n;
    
    int base;
    cin >> base;
    n--;
    
    while(n--){
        int top;
        cin >> top;
        
        int gcd_num;
        gcd_num = gcd(base, top);
        
        cout << base/gcd_num << '/' << top/gcd_num <<endl;
        
    }
 
}

