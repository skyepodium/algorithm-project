#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    int time;
    cin >> time;
    
    b = b+time;
    while(b>59){
        b = b - 60;
        a++;
    }
    if(a>23){
        a = a - 24;
    }
    
    cout << a <<" "<< b <<endl;
}

