#include <iostream>
#include <string>

using namespace std;

char first[8][4] = {"", "1", "10", "11", "100", "101", "110", "111"};
char other[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main(){
    string number;
    cin >> number;
    
    cout << first[number[0] - 48];
    
    for(int i=1; i < number.size(); i++){
        cout << other[number[i] - 48];
    }
    
    if(number =="0"){
        cout<<0<<endl;
    }
    
}
