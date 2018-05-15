#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string word;
    cin >> word;
    
    bool is_true = true;
    
    int size = (int)word.size();
    for(int i=0; i<size/2; i++){
        if(word[i] != word[size-i-1]){
            is_true = false;
            break;
        }
    }
    
    if(is_true) cout << "true" << endl;
    else cout << "false" << endl;
    
}



