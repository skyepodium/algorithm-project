#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    for (int a = 0; a <= t; a++){
        for(int c= 0; c< a; c++){
            cout<<" ";
        }

        for(int b = 0; b < (t-a);b++){
            cout<<"*";
        }
        
        cout<<"\n";
    }
}


