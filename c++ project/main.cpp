#include <iostream>
#include <string>

using namespace std;

int cnt = 0;
int q = 0;
void check_num(int num){
    int ret = num;
    while(num>0){
        ret = ret + num%10;
        num = num/10;
    }
    if(ret == q){
        cnt++;
    }
}

int main(){
    q = 101;
    for(int i=1; i<=101; i++){
        check_num(i);
    }
    cout << cnt << endl;
}