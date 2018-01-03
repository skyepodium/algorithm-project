#include <iostream>
#include <string>

using namespace std;

int main(){

    int t , n;
    string word;
    cin >> t;
    

    for(int i=1; i<=t; i++){
        cin >> n >> word;
        cout<<i<<" ";
            for(int i=0; i<word.size(); i++){
                if((i+1)!=n){
                    cout << word[i];
                }
            }
        cout << endl;
    }
}
