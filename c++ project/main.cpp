#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int go(int n){
    
    
    
    return 1;
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        
        int max_length = 0;
        for(int j=1; j<i; j++){
            
            if(a[i] < a[j]){
                max_length = max(max_length, d[j]);
            }
        }
        d[i] = max_length + 1;
    }
    
    int result = *max_element(d+1, d+n+1);
    
    cout << result << endl;
    
}
