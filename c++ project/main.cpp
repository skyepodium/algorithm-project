#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    string day;
    int num = 0;
    
    cout<<"오늘은 무슨 요일 입니까?";
    cin>>day;
    
    if(day == "sunday"){
        num = 1;
    }else if(day == "monday"){
        num = 2;
    }else if(day == "tuesday"){
        num = 3;
    }else if(day == "wednesday"){
        num = 4;
    }else if(day == "thursday"){
        num = 5;
    }else if(day == "friday"){
        num = 6;
    }else if(day == "토요일"){
        num = 7;
    }else{
        num = 8;
    }
    if(num < 8){
        cout<<"오늘은"<<day<<"이고 순서는"<<num<<"번째 입니다."<<endl;
    }else{
        cout<<"요일을 잘못 입력하셨습니다."<<endl;
    }
    
}

