#include <iostream>
#include <string>

using namespace std;

int main() {

    int cnt = 0;
    string word;
    for(int i=0; i<8; i++){
        cin >> word;
        
        for(int j=0; j<word.size(); j++){
            
            if(i%2 == 0 && j%2 == 0){
                if(word[j] == 'F'){
                    cnt++;
                }
            }else if(i%2 == 1 && j%2 == 1){
                if(word[j] == 'F'){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
