#include <iostream>

using namespace std;

int main(){
    
    long long int a, b, c;
    cin >> a >> b >> c;
    
    long long int result = 0;
    result = a*b - c;
    
    if(result > 0) cout << result << endl;
    else cout << 0 << endl;
    
    
}
