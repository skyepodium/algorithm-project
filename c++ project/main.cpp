#include <iostream>

using namespace std;

int main(){
    
    int a, b;
    cin >> a >> b;
    
    if(a==1 && b==2) cout << "B" << endl;
    else if(a==1 && b==3) cout << "A" << endl;
    else if(a==2 && b==1) cout << "A" << endl;
    else if(a==2 && b==3) cout << "B" << endl;
    else if(a==3 && b==1) cout << "B" << endl;
    else cout << "A" << endl;
    
}
