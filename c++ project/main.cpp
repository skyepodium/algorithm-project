#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    
    int a = 0;
    cin>>a;
    while(a--){
        int b;
        string c;
        cin>>b;
        cin>>c;
        
        for(int i=0; i<c.size(); i++){
            for(int j=0; j<b; j++){
                cout<<c[i];
            }
        }
        cout<<" ";
    }
}
