#include <iostream>
#include <string>

using namespace std;

int main() {

    string base, word;
    cin >> base >> word;
    
    int cnt = 0;
    for(int i=0; i<base.size(); i++){
        if(base[i] == word[0]){
            bool check = true;
            for(int j=0; j<word.size(); j++){
                if(base[i+j] != word[j]){
                    check = false;
                    break;
                }
            }
            if(check){
                cnt++;
            }
        }
    }
    
    cout << cnt <<endl;
    
}
