#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    int n;
    int num = 0;
    cin>>n;
    
    deque<int> s;
    
    while(n--){
        string cmd;
        cin>>cmd;
        
        if(cmd == "push_back"){
            cin>>num;
            s.push_back(num);
        } else if (cmd == "push_front"){
            cin>>num;
            s.push_front(num);
        } else if (cmd == "size"){
            cout<<s.size()<<endl;
        } else if (cmd == "empty"){
            cout<<s.empty()<<endl;
        } else if (cmd == "front"){
            if(s.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<s.front()<<endl;
            }
        } else if (cmd == "back"){
            if(s.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<s.back()<<endl;
            }
        } else if (cmd == "pop_front"){
            if(s.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<s.front()<<endl;
                s.pop_front();
            }
        } else{
            if(s.size() == 0){
                cout<<-1<<endl;
            }else{
                cout<<s.back()<<endl;
                s.pop_back();
            }
        }
        
        
        
    }
}
