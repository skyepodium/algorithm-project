#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        string num;
        cin >> num;
        
        int n = 0;
        
        for(int i=(int)num.size() - 1; i>=0; i--){
            
            if(i%2 == 0){
                int a = (num[i]-48)*2;
                if(a >= 10){
                    n = n + a/10 + a%10;
                }else{
                    n = n + a;
                }
            }else{
                n = n + (num[i]-48);
            }
        }
        
        if(n%10 == 0) cout << "T" << endl;
        else cout << "F" << endl;
        
    }
    
}
