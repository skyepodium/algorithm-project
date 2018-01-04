#include <iostream>

using namespace std;

int go(int n, int k){
    
    if(n==k || k==0){
        return 1;
    }
    
    return go(n-1, k-1) + go(n-1, k);
}


int main(){
    
    int a, b;
    cin >> a >> b;
    cout << go(a,b) << endl;
    
    
}

