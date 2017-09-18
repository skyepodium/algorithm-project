#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>



using namespace std;
string tentotwo(int num){
    string result;
    for(int i=1; num>0; i=i*10){
        int binary = num % 2;
        if(binary == 0){
            result.append("  ");
        }else{
            result.append("#");
        }
        num = num/2;
    }

    char temp;
    for(int i=0; i<result.size()/2; i++){
        temp = result[i];
        result[i] = result[result.size()-(i+1)];
        result[result.size()-(i+1)] = temp;
    }

    return result;
}
int main(){
    
    
    int a = 30;
   
    int b=28;
    int c=21;
    int d = b | c;
    cout<<d<<endl;
    cout<<tentotwo(d)<<endl;
}
