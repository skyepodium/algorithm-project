#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string word;
    cin >> word;
    
    for(int i=0; i<word.size(); i++){
        if(word[i] >=97 && word[i] <=122){
            word[i] = word[i] - 32;
        }
        printf("%c", word[i]);
    }
    cout << endl;
    
}
