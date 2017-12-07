#include <iostream>

using namespace std;

int cnt = 0;

void check_prime(int a){
    
    bool check = true;
    if(a<2){
        check = false;
    }else{
        for(int i=2; i*i<=a; i++){
            if(a%i == 0){
                check = false;
            }
        }
    }
    if(check){
        cnt++;
    }
}

int main() {

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        check_prime(a);
    }
    
    cout<<cnt<<endl;
}

