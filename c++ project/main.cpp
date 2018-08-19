#include <iostream>

using namespace std;

int a1[6] = {1, 3, 6, 10, 15, 21};
int a2[6] = {500, 300, 200, 50, 30, 10};

int b1[5] = {1, 3, 7, 15, 31};
int b2[5] = {512, 256, 128, 64, 32};


int main(){

    int t;
    cin >> t;
    
    while(t--){
        
        int a, b;
        cin >> a >> b;
        
        int result = 0;
        
        if(a>0 && a<=21){
            for(int i=0; i<6; i++){
                if(a <= a1[i]){
                    result = result + a2[i];
                    break;
                }
            }
        }
        
        if(b>0 && b<=31){
            for(int i=0; i<6; i++){
                if(b <= b1[i]){
                    result = result + b2[i];
                    break;
                }
            }
        }
        
        cout << result*10000 << endl;
        
    }
    
    
}
