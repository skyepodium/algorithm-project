#include <iostream>
#include <algorithm>

using namespace std;

int a[201];
int d[201];

int n;

int go(int i){

    d[i] = 1;
    if(d[i] > 1) return d[i];
    
    for(int j=0; j<n; j++){
        if(a[j] < a[i]){
            d[i] = max(d[i], d[j]+1);
        }
    }
    
    return d[i];
}

int main(){
    

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        go(i);
    }
    
    cout << n - *max_element(d, d+n) << endl;
    
}


