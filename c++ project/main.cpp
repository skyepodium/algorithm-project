#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cin >> word;
    
    int l_cnt = 0;
    int r_cnt = 0;
    bool face = false;
    for(int i=0; i<(int)word.size(); i++){
        if(word[i] == '(') face = true;
        
        if(word[i] == '@'){
            if(!face) l_cnt++;
            else r_cnt++;
        }
    }
    
    printf("%d %d\n", l_cnt, r_cnt);
}
