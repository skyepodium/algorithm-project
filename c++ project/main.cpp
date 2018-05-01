#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool check[9];


bool check_num(int a, int b){

    bool is_possible = true;
    
    while(a>0){
        
        if(check[a%10] == false){
            check[a%10] = true;
        }else{
            is_possible = false;
            break;
        }
        a = a/10;
    }

    
    if(is_possible == true){
        while(b>0){
            if(check[b%10] == false){
                check[b%10] = true;
            }else{
                is_possible = false;
                break;
            }
            b = b/10;
        }
    }
    
    if(is_possible == true) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    
    bool is_possible = false;
    for(int i=n; i>=1; i--){
        
        if(n-i > 0){
            memset(check, false, sizeof(check));
            if(check_num(i, n-i) == true){
                is_possible = true;
                cout << i << " + " << n-i << endl;
                break;
            }
        }
    }
    
    if(is_possible == false) cout << -1 << endl;
    
}
