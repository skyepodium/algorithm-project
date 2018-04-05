#include <iostream>
#include <algorithm>

using namespace std;

//call by reference
int calc(int &a){
    
    
    return a+1;
}

int main(){
    
    int a = 3;
    
    cout << calc(a) << endl;

}
