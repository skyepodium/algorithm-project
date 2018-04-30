#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    n = n - 1;
    
    for(int i=1; i<=10101; i++){
        if(i*(i+1) == n){
            cout << i << endl;
            break;
        }
    }
}
