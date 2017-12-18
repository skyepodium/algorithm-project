#include <iostream>

using namespace std;

bool check[42];

int main(){
    
    for(int i=0; i<42; i++){
        check[i] = false;
    }

    int num;
    int mod;
    for(int i=0; i<10; i++){
        cin >> num;
        mod = num%42;
        if(!check[mod]){
            check[mod] = true;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<42; i++){
        if(check[i]){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    
}

