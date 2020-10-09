#include <iostream>
#include <stack>
using namespace std;

int t, n, num, result;
stack<int> s;

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            
            if(num != 0) {
                s.push(num);
            }
            else{
                s.pop();
            }
        }
        
        result = 0;
        
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        
        printf("#%d %d\n", test_case, result);
    }
}
