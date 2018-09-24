#include <iostream>
#include <cstring>
#include <stack>
#define max_int 1000001

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 없음
//사용한 자료구조: 스택


char cmd[max_int];
int t;

int main(){
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%s", cmd);
        
        stack<char> left;
        stack<char> right;
        
        int length = (int)strlen(cmd);

        for(int i=0; i<length; i++){
            if(cmd[i] == '<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            }
            
            else if(cmd[i] == '>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
            }
            
            else if(cmd[i] == '-'){
                if(!left.empty()){
                    left.pop();
                }
            }
            
            else{
                left.push(cmd[i]);
            }
        }
        
        while(!left.empty()){
            right.push(left.top());
            left.pop();
        }
        
        while(!right.empty()){
            printf("%c", right.top());
            right.pop();
        }
        printf("\n");
        
    }
}
