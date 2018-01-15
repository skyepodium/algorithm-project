#include <iostream>
#include <algorithm>

using namespace std;

int d1[100001];
int d2[100001];
int a[100001];

int main(){
    
    int n;
    cin >> n;
    
    int result = -1001;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d1[i] = a[i];
        d2[i] = a[i];
    }
    for(int i=1; i<=n; i++){
        d1[i] = max(d1[i-1] + a[i], a[i]);
    }
    
    for(int i=n; i>=1; i--){
        d2[i] = max(d2[i+1] + a[i], a[i]);
    }
    
    for(int i=1; i<=n; i++){
        if(d1[i] < d1[i-1] + d2[i+1]){
            result = max(d1[i-1] + d2[i+1], result);
        }else{
            result = max(d1[i], result);
        }
    }
    
    
    cout << result << endl;
}
