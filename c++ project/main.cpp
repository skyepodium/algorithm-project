#include <iostream>

using namespace std;

int main(){
        
    int t;
    cin >> t;

    
    int a, b;
    while(t--){
        cin >> a >> b;
        
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", a/b, a%b );
    }
}

