#include <iostream>
#include <algorithm>

using namespace std;

int d[100001] = {0};
int a[100001] = {0};

int main(){

    int n;
    cin >> n;
    
    int result = -1001;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = max(d[i-1] + a[i], a[i]);
        result = max(result, d[i]);
    }
    
    cout << result << endl;
}
