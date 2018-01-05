#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int before = 1001;
    int current = 0;
    int diff = 0;
    int result = 0;
    
    for(int i=1; i<=n; i++){
        
        cin >> current;
        
        diff = before < current ? diff + current - before : 0;
        
        result = max(result, diff);
        before = current;
    }
    
    cout << result << endl;
}
