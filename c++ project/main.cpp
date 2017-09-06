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
    
    int n = str.size();
    char s[n][256];
    
    for(int i=0; i<str.size(); i++){
        for(int j=0; j<str.size(); j++){
            s[i][j] = str[i];
        }
    }
    for(int i=0; i<256; i++){
        if(s[0][i]>0){
//            cout<<s[0][i]<<endl;
        }
    }
}

