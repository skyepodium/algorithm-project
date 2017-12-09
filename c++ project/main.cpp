#include <iostream>
#include <string>
#include <vector>

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
    
    int n;
    cin >> n;
    
    const int max_size = 10000000;
    bool *check = new bool[max_size+1];
    check[1] = false;
    for(int i=0; i<=max_size; i++){
        check[i] = true;
    }
    
    check = eratos(max_size+1, check);
    
    vector<int> v;
    for(int i=2; i<=n; i++){
        if(check[i] && n%i == 0){
            v.push_back(i);
        }
    }
    for(int i=0; i<v.size(); i++){

        while(n%v[i] == 0){
            n = n/v[i];
            cout << v[i] <<endl;
        }
        
    }
}
