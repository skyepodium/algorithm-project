#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t--){
        
        int base;
        cin >> base;
        
        int n;
        cin >> n;
        
        int num, price;
        for(int i=0; i<n; i++){
            cin >> num >> price;
            base = base + num * price;
        }
        
        cout << base <<endl;
    }
    
}

