#include <iostream>
#include <string>
using namespace std;

string s = "qwer";

int main() {
    int size =(int)s.size();
    if(size%2 == 1){
        cout << s[size/2] << endl;
    }
    else{
        cout << s[size/2 - 1] << s[size/2] << endl;
    }
}