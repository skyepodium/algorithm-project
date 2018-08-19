#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        string num;
        cin >> num;
        
        if(num[num.size()-1]%2 == 0) cout << "even" << endl;
        else cout << "odd" << endl;
    }
}

