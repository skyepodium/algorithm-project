#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string num1, num2;
    cin >> num1 >> num2;
    
    bool is_right = true;
    if(num1.size() == num2.size()){
        
        for(int i=0; i<num1.size(); i++){
            if(num1[i] != num2[i]){
                is_right = false;
                break;
            }
        }
        
    }else is_right = false;
    
    if(is_right == true) cout << 1 << endl;
    else cout << 0 << endl;
}
