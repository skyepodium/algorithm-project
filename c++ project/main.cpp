#include <iostream>
#include <string>

using namespace std;

int main(){

    string word;
    cin >> word;
    
    int cnt = 0;
    int size = (int)word.size();
    for(int i=0; i<size; i++){
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            cnt++;
        }
    }
    
    cout << cnt << endl;

}
