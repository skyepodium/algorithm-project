#include <iostream>
#include <string>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 리니어 서치
//사용한 자료구조: 스트링

int main(int argc, const char *argv[]) {
    int T;
    cin >> T;
    
    while(T--){
        string word;
        cin >> word;
        
        char current_c = word[0];
        int cnt = 1;
        
        for(int i=1; i<word.size(); i++){
            if(word[i] != word[i-1]){
                cout << cnt;
                printf("%c", current_c);
                current_c = word[i];
                cnt = 1;
            }else{
                cnt++;
            }
            
            if(i == (word.size()-1)){
                cout << cnt;
                printf("%c", current_c);
            }
            
        }
        
        
        cout << endl;
    }
    
    
    return 0;
}

