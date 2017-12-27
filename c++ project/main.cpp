#include <iostream>

using namespace std;

int d[1001] = {0};
int a[1001] = {0};

int go(int n){

    if(d[n] > 0){
        return d[n];
    }
    
    int base = 0;
    for(int i=1; i<n; i++){
        if(a[i] < a[n] && go(i) > base){
            base = go(i);
        }
    }
    d[n] = base + 1;
    
    return d[n];
}


int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int max = 0;
    for(int i=1; i<=n; i++){
        if(max<go(i)){
            max = go(i);
        }
    }
    
    cout << max << endl;
}
