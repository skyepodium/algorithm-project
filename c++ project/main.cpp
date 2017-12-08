#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n, han = 0;
    cin >> n;
    
    vector<int> v;
    
    if(n < 100){
        
        han = n;
        
    }else{
        han = 99;
        
        if(n == 1000){
            n = n-1;
        }
        
        for(int i=100; i<=n; i++){
            int t = i;
            while(t > 0){
                v.push_back(t%10);
                t = t/10;
            }
            if(v[0] - v[1] == v[1] - v[2]){
                han++;
            }
            v.clear();
        }
    }
    
    cout << han << endl;
}



