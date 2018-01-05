#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = a[i];
    }
    
    for(int i=1; i<=n; i++){
        int max_val = 0;
        for(int j=1; j<i; j++){
            if(a[j] < a[i]){
                max_val = max(max_val, d[j]);
            }
        }
        d[i] = max_val + a[i];
    }
    
    cout << *max_element(d+1, d+n+1) << endl;
}


