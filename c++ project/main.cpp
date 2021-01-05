#include <iostream>
#include <cstring>
#include <stack>
#define max_int 10001
using namespace std;

int t;
char a[max_int];

void solve() {
    scanf("%s", a);
   
    int size = (int)strlen(a);
    stack<int> s;
    char cur, top;
    bool result = true;
    
    for(int i=0; i<size; i++) {
        cur = a[i];
        
        if(cur == '(' || cur == '{' || cur == '[') {
            s.push(cur);
        }
        else {
            if(s.size() == 0) {
                result = false;
                break;
            }
            top = s.top();
            
            if(cur == ')' && top == '(') {
                s.pop();
            }
            else if(cur == '}' && top == '{') {
                s.pop();
            }
            else if(cur == ']' && top == '[') {
                s.pop();
            }

        }
    }
    if(s.size() > 0) result = false;
    
    if(result) printf("YES\n");
    else printf("NO\n");
}

int main() {
    scanf("%d", &t);
    
    while(t--) {
        solve();
    }
}
