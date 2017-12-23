#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string word;
    cin >> word;
    
    for(int i=0; i<word.size(); i++){
        if(word[i] >= 68){
            printf("%c", word[i] - 3);
        }else{
            printf("%c",  word[i] + 23);
        }
    }
    cout<<endl;
}
