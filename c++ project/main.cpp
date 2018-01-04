#include <iostream>

using namespace std;

int a[101];

int gcd(int a, int b){
    
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
    
}

int main(){
 
    int t, n;
    cin >> t;
    
    while(t--){

        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        long long int result = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                result += gcd(a[i],a[j]);
            }
        }
        
        cout << result << endl;
    }
    
}

