#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    
    for (int a=0; a < t; a++){
        for(int b=0; b < a; b++){
            cout<< " ";
        }
        for(int c=0; c <= 2*(t-1)-a*2; c++){
            cout<< "*";
        }
        cout<<"\n";
    }
    
    for (int a = 2; a <= t; a++){
        for(int c= 1; c<=t-a; c++){
            cout<<" ";
        }
        
        for(int k=1; k < 2*a; k++){
            cout<<"*";
        }
        cout<<"\n";
    }

}


