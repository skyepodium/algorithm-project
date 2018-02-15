#include <iostream>

using namespace std;

int d[1000][10];
int mod = 10007;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k]%mod;
                d[i][j] %= mod;
            }
        }
    }
    
    int result = 0;
    for(int i=0; i<10; i++){
        result += d[n][i]%mod;
        result %= mod;
    }
    cout << result%mod << endl;
}
