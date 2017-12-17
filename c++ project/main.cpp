#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    while(n--){
        int a;
        cin >> a;
        
        vector<int> v;
        
        while(a>0){
            v.push_back(a%2);
            a = a/2;
        }
        
        int size = (int)v.size();
        
        for(int i=0; i<size; i++){
            if(v[i] == 1){
                cout<<i<<" ";
            }
        }

    }
}
