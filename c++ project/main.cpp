#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int cnt = 0;
    bool is_check = false;
    for(int i=1; i*i<=n; i++){
        
        if(n%i == 0) cnt++;
        if(i*i == n) is_check = true;
        
    }
    
    int result = 0;
    if(is_check == true) result = (cnt-1) * 2 + 1;
    else result = cnt*2;
    
    cout << result << endl;
    
}
