#include <iostream>
#include <string>
using namespace std;

void go(int idx, string result) {
    if(idx >= 26) {
        if(result.size() == 3) {
            cout << result << endl;
        }
        return;
    }
    
    go(idx + 1, result + char(idx + 97));

    go(idx + 1, result);
}

int main() {
    go(0, "");
}
