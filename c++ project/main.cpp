#include <iostream>
#include <stack>

using namespace std;

int n;
char cmd;
string word;
stack<char> first;
stack<char> second;

int main(){
    cin >> word;
    for(int i=0; i<(int)word.size(); i++){
        first.push(word[i]);
    }

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == 'P'){
            cin >> cmd;
            first.push(cmd);
        }
        else if(cmd == 'L'){
            if(first.size()>0){
                char temp;
                temp = first.top();
                first.pop();
                second.push(temp);
            }
        }
        else if(cmd == 'D'){
            if(second.size()>0){
                char temp;
                temp = second.top();
                second.pop();
                first.push(temp);
            }
        }
        else{
            if(first.size()>0) first.pop();
        }
    }

    while(!first.empty()){
        second.push(first.top());
        first.pop();
    }
    while(!second.empty()){
        cout << second.top();
        second.pop();
    }
    printf("\n");
}