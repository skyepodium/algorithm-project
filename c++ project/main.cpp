#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int main(){
    
    int n;
    cin >> n;
    
    int is_continue = false;
    int result = 0;
    
    d[0] = 0;
    a[0] = 1001;

    for(int i=1; i<=n; i++){

        cin >> a[i];
        
        if(a[i] > a[i-1]){
            d[i] = a[i] - a[i-1];

            if(is_continue){
                d[i] += d[i-1];
            }

            result = max(d[i], result);
            is_continue = true;
            
        }else{
            is_continue = false;
        }
        
    }
    
    cout << result << endl;
}
