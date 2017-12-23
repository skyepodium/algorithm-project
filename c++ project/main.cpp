#include <iostream>
#include <string>

using namespace std;


int main() {
    
    string num1, num2;
    cin >> num1 >> num2;
    
    int num1_size = (int)num1.size();
    int num2_size = (int)num2.size();
    
    for(int i=0; i<num1_size/2; i++){
        
        char temp;
        temp = num1[i];
        num1[i] = num1[num1_size-1-i];
        num1[num1_size-1-i] = temp;
        
    }

    for(int i=0; i<num2_size/2; i++){
        
        char temp;
        temp = num2[i];
        num2[i] = num2[num2_size-1-i];
        num2[num2_size-1-i] = temp;
        
    }

    int result_mid = stoi(num1) + stoi(num2);
    string result = to_string(result_mid);

    int result_size = (int)result.size();

    for(int i=0; i<result_size/2; i++){
        
        char temp;
        temp = result[i];
        result[i] = result[result_size-1-i];
        result[result_size-1-i] = temp;
        
    }
    
    cout<<stoi(result)<<endl;
}
