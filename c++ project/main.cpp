#include <iostream>

using namespace std;

int cal_result(int a){
    
    int result = 0;
    
    while(a > 0){
        
        result = result + a%10;
        a = a / 10;
    }
    
    return result;
}

int main(){
    
    int n;
    cin >> n;
    
    cout << cal_result(n) << endl;
}
