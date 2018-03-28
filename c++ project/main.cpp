#include <iostream>
#include <algorithm>

using namespace std;

long long int d[101];

long long int go(int i){
    
    if( i <= 6){
        d[i] = i;
        return d[i];
    }
    
    if( d[i] > 0){
        return d[i];
    }
    
    for(int j=3; j<=i-1; j++){
        d[i] = max(d[i], go(i-j) * (j-1));
    }
    
    return d[i];
}


int main() {
    
    int n;
    cin >> n;
    
    cout << go(n) << endl;
    
}
