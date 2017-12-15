#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    
    cout.setf(ios::fixed | ios::showpoint);
    
    cout << "$" << setprecision(2) <<10.3 <<" " <<"$" <<20.5<<endl;
    
}
