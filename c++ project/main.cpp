#include <iostream>
#include <string>
#include <stack>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: string class, STL 스택

int main(){
    string word;
    cin >> word;
    int size = (int)word.size();
    
    stack<int> s;
    
    int result = 0;
    for(int i=0; i<size; i++){
        if(word[i] == '('){
            s.push(i);
        }else{
            if(i-1 == s.top()){
                s.pop();
                result += (int)s.size();
            }else{
                s.pop();
                result += 1;
            }
        }
    }
    
    cout << result << endl;
    
}
