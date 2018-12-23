#include <iostream>

#define max_int 100001
using namespace std;

string word;

int main(){
    cin >> word;
    int result = 0;
    int cnt = 0;
    int prev = 0;
    
    for(int i=0; i<(int)word.size(); i++){
        if(word[i] == '('){
            prev = 1;
            cnt++;
        }
        else{
            if(prev == 1){
                prev = 0;
                if(cnt != 1){
                    result += (cnt - 1);
                    cnt--;
                }
                else{
                    cnt = 0;
                }
            }
            else{
                prev = 0;
                cnt--;
                result += 1;
            }
        }

    }
    
    printf("%d\n", result);
    
    
}
