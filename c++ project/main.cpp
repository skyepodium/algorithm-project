#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin >> word;

    bool check = true;
    int size = (int)word.size();
    for(int i=0; i<size/2; i++){
        if(word[i] != word[size-1-i]){
            check = false;
        }
    }
    if(check){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}

