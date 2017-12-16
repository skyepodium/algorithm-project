#include <iostream>
#include <string>

using namespace std;

int main(){

    string word;

    while(getline(cin, word)){
        
        if(word != "END"){
        int size = (int)word.size();

        for(int i=size-1; i>=0; i--){
            cout<<word[i];
        }
        cout<<endl;
        }else{
            break;
        }

    }
}
