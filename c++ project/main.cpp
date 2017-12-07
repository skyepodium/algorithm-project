#include <iostream>
#include <string>

using namespace std;

int n, k;

void eratos(int a){
    bool *check = new bool[a+1];
    check[1] = false;
    for(int i=2; i<=a; i++){
        check[i] = true;
    }
    
    int cnt = 0;
    
    for(int i=2; i<=a; i++){
        for(int j=i; j<=a; j=j+i){
            if(check[j]){
                check[j] = false;
                cnt++;
                if(cnt == k){
                    cout<< j <<endl;
                }
            }
        }
    }
}

int main() {
    
    cin >> n >> k;
    
    eratos(n);
}



