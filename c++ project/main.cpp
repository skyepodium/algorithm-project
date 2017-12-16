#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    while(n--){
        int a;
        cin >> a;
        
        int sum = 0 ;
        for(int i=0; i<a; i++){
            int b;
            cin >> b;
            sum = sum + b;
        }
        cout << sum << endl;
    }

}
