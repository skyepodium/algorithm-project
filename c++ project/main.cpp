#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    
    int a;
    cin>>a;
    
    long total =1;
    for(int i=1; i<=a; i++){
        total=total*i;
    }
    string word =to_string(total);
    
    cout<<total<<endl;
    for(int i=0; i<word.size(); i++){

        if(a ==0){
            cout<<1;
            break;
        }
        
        if(word[word.size()-1]!=48){
            cout<<0;
            break;
        }

        total = total/10;
        
        if(total%10 != 0){
            cout<<i+1<<endl;
            break;
        }
    }
    
}
