#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    
    string num;
    cin >> num;
    
    int result = 0;
    for(int i=0; i<num.size(); i++){
        
        int mul_num = 0;
        if(num[i] >=65) mul_num = num[i] - 55;
        else mul_num = num[i] - 48;
        
        result = result + mul_num*pow(16,num.size()-1-i);
    }
    cout << result << endl;

}

