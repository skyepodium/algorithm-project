#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    int a, b, v, day = 1;
    cin >> a >> b >> v;
    day += (v-a)/(a-b);
    if((v-a)%(a-b) != 0){
        day++;
    }

    cout << day << endl;
}
