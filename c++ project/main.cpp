#include <iostream>
#include <algorithm>

using namespace std;

long long int d[1000001];
long long int mod = 1000000009;

int main(){
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    
    for(long long int i=4; i<=1000000; i++){
        d[i] = d[i-1]%mod + d[i-2]%mod + d[i-3]%mod;
        d[i] %= mod;
    }
    
    long long int n;
    cin >> n;
    
    for(long long int i=0; i<n; i++){
        long long int num;
        cin >> num;
        
        cout << d[num]%mod << endl;
    }
    
    
    
}

