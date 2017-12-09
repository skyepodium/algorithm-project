#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

bool* eratos(int n, bool *check){
    
    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j=j+i){
            check[j] = false;
        }
    }
    
    return check;
}

int main() {

    int t;
    cin >> t;
    
    const int max_size = 10000;
    bool *check = new bool[max_size+1];
    check[1] = false;
    for(int i=0; i<=2*max_size; i++){
        check[i] = true;
    }
    
    check = eratos(max_size+1, check);

    while(t--){
        int a;
        cin >> a;
        int min = 0;
        int index = 0;

        for(int j=2; j<=a/2; j++){
            if(check[j] && check[a-j]){
                if(min == 0){
                    min = (a-j) - j;
                    index = j;
                }else if(min != 0){
                    if(min > (a-j) - j){
                        min = (a-j) - j;
                        index = j;
                    }
                }
            }
        }
        cout << index << " " << a-index <<endl;
    }
    
}


