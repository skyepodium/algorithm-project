#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    string word;
    while(cin >> word){
        
        if(word!="0"){
            
            while(word.size()>1){
                int sum = 0;
                for(int i=0; i<word.size(); i++){
                    sum += word[i] - 48;
                }
                word = to_string(sum);
            }
            cout << word << endl;
        }else{
            break;
        }
    }
}
