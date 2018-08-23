#include <iostream>
#include <string>
#include <stack>

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: string class(스택)

using namespace std;

int main(){
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;

        stack<char> s;
        
        bool is_right = true;
        for(int i=0; i<word.size(); i++){
            if(word[i] == '('){
                s.push('(');
            }else{
                if(s.size() == 0){
                    is_right = false;
                    break;
                }
                s.pop();
            }
        }
        
        if(s.size() != 0) is_right = false;
        if(is_right == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    
    
    
}
