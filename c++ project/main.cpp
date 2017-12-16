#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a;
    int one = 0;
    int zero = 0;
    while(n--){
        cin >> a;
        if(a == 0){
            one++;
        }else{
            zero++;
        }
    }
    
    if(one > zero){
        cout<<"Junhee is not cute!"<<endl;
    }else{
        cout<<"Junhee is cute!"<<endl;
    }
}

