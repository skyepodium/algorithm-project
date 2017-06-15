#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    
    for (int a=0; a < t; a++){
        
        if(t%2 == 0){
            for(int b=a; b < t-1; b++){
                cout<<" ";
            }
            for(int c=t; c < t+2*(a)+1; c++){
                if(c%2 == 0 ){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }
            cout<<"\n";
        }else{
            
            for(int b=a; b< t-1; b++){
                cout<<" ";
            }
            for(int c=t; c< t+2*(a)+1; c++){
                if(c%2 == 1 ){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
                
            }
            cout<<"\n";
        }
    }
}


