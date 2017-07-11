#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int p[10001];
    p[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    
    int d[1001];
    d[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(d[i], d[i-j]+p[j]);
        }
    }
    cout<<d[n]<<endl;
}
