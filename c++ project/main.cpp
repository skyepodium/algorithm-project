#include <iostream>

using namespace std;

int main(){
    
    int a;
    char b;
    int result = 0;
    while(cin >> a >> b){
        
        result = result + a;
        
        if(b!=','){
            break;
        }
        
    }
    cout << result << endl;
}


