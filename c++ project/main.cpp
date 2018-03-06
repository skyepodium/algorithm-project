#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: string class, STL 스택

string check(string word){
    
    stack<int> s;
    for(int i=0; i<word.size(); i++){
        
        if(word[i] == 40 || word[i] == 91 || word[i] == 123){
            
            s.push(word[i]);
            
        }else{
            
            if(s.size()!=0){//닫는 괄호는 스택의 크기가 1이상일때 들어와야한다. 열고 닫아야 하니까
                if(word[i] > 41){
                    if(word[i] != s.top()+2){//스택의 top과 짝이 맞지 않으면 NO 리턴, 맞으면 POP
                        return "NO";
                    }else{
                        s.pop();
                    }
                }else{
                    if(word[i] != s.top()+1){//스택의 top과 짝이 맞지 않으면 NO 리턴, 맞으면 POP
                        return "NO";
                    }else{
                        s.pop();
                    }
                }
            }else{//스택이 비어있는데 닫는 괄호가 들어왔다, 틀린 괄호 문자열이다.
                return "NO";
            }
            
        }
        
    }
    
    
    if(s.size() == 0){//문자열을 다 검사했는데, 스택의 크기가 0이면 옳은 문자열이다.
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
