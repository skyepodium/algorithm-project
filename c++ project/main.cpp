#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){

        for(int j=0; j<i+1; j++){
            cout<<'*';
        }
        cout<<endl;
    }
    
    for(int i=0; i<t-1; i++){
        
        for(int j=0; j<t-i-1; j++){
            cout<<'*';
        }
        cout<<endl;
    }
}
