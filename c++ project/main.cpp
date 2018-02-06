#include <iostream>

using namespace std;

long long int d[81];

int main(){
    
    int n;
    cin >> n;
    
    d[1] = 4;
    d[2] = 6;
    for(int i=3; i<=n; i++){
        d[i] = d[i-1] + d[i-2];
    }
    
    cout << d[n] << endl;
    
}
