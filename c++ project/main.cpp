#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    for(int k=0; k<2*n; k++){
        if(k%2 == 1){
            cout<<' ';
        }
        
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                if((n-k)%2 == 0 && i == n-1){
                    continue;
                }else{
                    cout<<'*';
                }
            }else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
}

