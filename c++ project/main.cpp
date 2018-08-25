#include <iostream>
#include <string>

//시간 복잡도: O(n)
//공간 복잡도: O(1)
//사용한 알고리즘: 없음
//사용한 자료구조: string class(스택)

using namespace std;

int main(){
    
    string word;
    getline(cin, word);
    
    for(int i=0; i<word.size(); i++){
        
        char ch = word[i];
        if(ch >= 97){
            
            if(ch + 13 > 122){
                printf("%c", ch + 13 - 26);
            }else{
                printf("%c", ch + 13);
            }
            
        }else if(ch >= 65){

            if(ch + 13 > 90){
                printf("%c", ch + 13 - 26);
            }else{
                printf("%c", ch + 13);
            }

        }else{
            printf("%c", ch);
        }
        
    }
    cout << endl;
}
