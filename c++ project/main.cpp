#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string word;
    cin >> word;
    
    for(int i=0; i<word.size(); i++){
        if(word[i] != 45 && word[i] <= 90){
            cout << word[i];
        }
    }
    cout << endl;
    
}


