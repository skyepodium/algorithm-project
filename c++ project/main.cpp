#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    while(true){
        int n;
        cin >> n;
        
        if(n == 0){
            break;
        }
        
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        vector<int> d;
        for(int i=0; i<6; i++){
            d.push_back(1);
        }
        for(int i=0; i<n-6; i++){
            d.push_back(0);
        }
        
        do{
            for(int i=0; i<n; i++){
                if(d[i] == 1){
                    cout << v[i] <<" ";
                }
            }
            cout << endl;
        }while(prev_permutation(d.begin(), d.end()));
        cout << endl;
    }
}
