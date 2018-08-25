#include <iostream>

using namespace std;

int mod = 1000000000;

int d[201][201];

int main(){
    
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<=n; i++){
        
        d[i][1] = 1;
        
        for(int j=0; j<=n; j++){
            for(int h=1; h<=k; h++){
                d[i][h] = d[i][h]%mod + d[j][h-1]%mod;
                d[i][h] %= mod;
            }
        }
    }
    
    cout << d[n][k] << endl;
}

