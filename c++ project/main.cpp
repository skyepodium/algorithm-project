#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    
    int a,b;
    cin>>a>>b;
    
    int array[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 
    int total=0;
    for(int i=0; i<a-1; i++){
        total= total+array[i];
    }
    total=total+b;
    int result=total%7;
    
    if(result == 1){
        cout<<"MON";
    }else if(result == 2){
        cout<<"TUE";
    }else if(result == 3){
        cout<<"WED";
    }else if(result == 4){
        cout<<"THU";
    }else if(result == 5){
        cout<<"FRI";
    }else if(result == 6){
        cout<<"SAT";
    }else{
        cout<<"SUN";
    }
}
