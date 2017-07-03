#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    int n;
    int m;
    
    int num = 0;
    
    cin>>n;
    cin>>m;
    queue<int> s;
    
    for(int i=1; i<=n; i++){
        s.push(i);
    }

    cout<<"<";
    while(n--){
        for(int i=0; i<m; i++){
        num = s.front();
        s.pop();
            
            if(i<m-1){
            s.push(num);
            }
        }
        cout<<num;
        if(n!=0){
            cout<<", ";
        }
    }
    cout<<">"<<endl;
}
