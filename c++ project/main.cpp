#include <iostream>
#include <string>
#include <stack>

using namespace std;

string check(string word){
    
    stack<int> s;
    for(int i=0; i<word.size(); i++){

        if(word[i] == 40 || word[i] == 91 || word[i] == 123){

            s.push(word[i]);

        }else{
            
            if(s.size()!=0){
                if(word[i] > 41){
                    if(word[i] != s.top()+2){
                        return "NO";
                    }else{
                        s.pop();
                    }
                }else{
                    if(word[i] != s.top()+1){
                        return "NO";
                    }else{
                        s.pop();
                    }
                }
            }else{
                return "NO";
            }
            
        }
        
    }
    
    
    if(s.size() == 0){
        return "YES";
    }else{
        return "NO";
    }
}


int main(){

    int t;
    cin >> t;
    
    while(t--){
        
        string word;
        cin >> word;
        
        cout << check(word) << endl;
        
    }

}
