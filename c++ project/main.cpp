#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    int n = 0;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        n = n + a;
    }

    cout << n - t + 1<<endl;
}


