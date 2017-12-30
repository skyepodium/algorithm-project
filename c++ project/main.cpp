#include <iostream>
#include <string>

using namespace std;

int d[10001];
int a[101];

int main(){
    
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<=10000; i++){
        d[i] = 0;
    }
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=a[i]; j<=k; j++){
            d[j] = d[j] + d[j-a[i]];
        }
    }
    
/*
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i-a[j] > 0){
                d[i] = d[i] + d[i - a[j]];
                cout <<"i "<<i<<" d[i] "<<d[i] <<endl;
            }
        }
    }
 */
    cout << d[k] << endl;
}
