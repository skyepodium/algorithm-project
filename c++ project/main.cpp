#include <iostream>

using namespace std;

long long d[201][201];
long long int mod = 1000000000;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    d[0][0] = 1;
    for(int i=0; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                d[i][j] += d[i-1][j-l];
                d[i][j] %= mod;
            }
        }
    }
    cout << d[k][n] << endl;
}
