#include <iostream>
#include <string>

using namespace std;

int main(){

    string word;
    cin >> word;
    
    int cnt = 0;
    for(int i=0; i<word.size(); i++){
        if(word[i] == ','){
            cnt++;
        }
    }
    cout<<cnt+1<<endl;
}
