#include <iostream>
using namespace std;

int main() {
    
    int t, num;
    cin >> t;
    
    while(t--){
        
        cin >> num;
        
        for(int i=0; i<num; i++){
            cout<<'=';
        }
        cout<<endl;
    }
}
