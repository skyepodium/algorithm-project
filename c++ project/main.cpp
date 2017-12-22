#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    int b;
    cin >> b;
    
    string word;
    while(t--){
        cin>>word;
        int size = (int)word.size();
        
        for(int i=size-1; i>=0; i--){
            cout<<word[i];
        }
        cout<<endl;
    }

}
