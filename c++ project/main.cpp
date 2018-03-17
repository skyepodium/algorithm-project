#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool check[101];

int main(){

    for(int i=2; i<101; i++){
        for(int j=i; j<101; j=j+i){
            if(check[j] == false){
                check[j] = true;
            }else{
                check[j] = false;
            }
            
        }
    }

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(check[i] == false){
                cnt++;
            }
        }
        cout << cnt << endl;

    }
}

