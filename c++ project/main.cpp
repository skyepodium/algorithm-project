#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string num1, num2;
    char op;
    
    cin >> num1 >> op >> num2;

    int num1_size = (int)num1.size();
    int num2_size = (int)num2.size();
    
    
    if(op == '*'){
  
        num1.append(num2.begin()+1, num2.end());
        cout << num1 <<endl;
        
    }else{

        if(num1_size == num2_size){
            
            num1[0] = '2';
            cout<<num1<<endl;
            
        }else if(num1_size < num2_size){

            num2[num2_size - num1_size] = '1';
            cout << num2 <<endl;

        }else{

            num1[num1_size - num2_size] = '1';
            cout << num1 <<endl;

        }
    }
}

