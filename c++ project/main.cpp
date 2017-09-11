#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    string str;
    cin>>str;
    
    int check;
    int cnt = 0;
    int max=0;
    int check2 = 0;
    for(int i=0; i<str.size(); i++){
        check = str[i];
        for(int j=0; j<str.size(); j++){
            if(str[j] == str[i]){
                cnt = cnt+1;
            }
        }
        if(cnt > max){
            max = cnt;
        }
        if(max == cnt){
            check2 = 1;
        }
        cnt = 0;
    }
    
    if(check2 == 1){
        cout<<"?"<<endl;
    }else{
        cout<<max<<endl;
    }
}

