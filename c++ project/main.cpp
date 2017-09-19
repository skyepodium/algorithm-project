#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <time.h>
using namespace std;
int main(){

    int a=time(0);
    srand(a);
    int b = rand();

    int result = b%3;
    
    string comresult;
    if(result == 0){
        comresult = "rock";
//        cout<<"컴퓨터 주먹임"<<endl;
    }else if(result == 1){
        comresult = "scissor";
//        cout<<"컴퓨터 가위임"<<endl;
    }else{
        comresult = "paper";
//        cout<<"컴퓨터 보자기임"<<endl;
    }
    
    string word;
    cout<<"가위바위보 게임"<<endl;
    cout<<"너 뭐 낼래? 영어로 적어라, rock, scissor, paper"<<endl;
    cin>>word;
    
    int aa;
    if(word == "rock"){
        if(comresult == "rock"){
            aa = 0;
        }else if(comresult == "paper"){
            aa = -1;
        }else{
            aa = 1;
        }
    }else if(word == "paper"){
             if(comresult == "rock"){
                 aa = 1;
             }else if(comresult == "paper"){
                 aa = 0;
             }else{
                 aa = -1;
             }
    }else{
        if(comresult == "rock"){
            aa = -1;
        }else if(comresult == "paper"){
            aa = 1;
        }else{
            aa = 0;
        }
    }

    if(aa == 1){
        cout<<"너 이김"<<endl;
    }else if(aa == 0){
        cout<<"너 비김"<<endl;
    }else{
        cout<<"너 짐"<<endl;
    }
}
