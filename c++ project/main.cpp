#include <iostream>

using namespace std;

void go(int idx, int num) {
    if (idx > 4) {
        cout << num << endl;
        return;
    }
        
    go(idx + 1, num + idx);
    
    go(idx + 1, num);
}
    
int main() {
    
    go(0, 0);
}
