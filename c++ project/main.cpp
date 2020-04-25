#include <iostream>
#include <string>
#define max_int 11
using namespace std;

int num;
bool check[max_int];
string cmd1, cmd2;

int main(){
    while(true){
        scanf("%d", &num);
        if(num == 0) break;

        cin >> cmd1 >> cmd2;

        if(cmd2 == "high"){
            for(int i=num; i<=10; i++) check[i] = true;
        }
        else if(cmd2 == "low"){
            for(int i=num; i>=1; i--) check[i] = true;
        }else if(cmd2 == "on"){
            bool isTrue = true;
            if(check[num]) isTrue = false;

            if(isTrue) cout << "Stan may be honest" << endl;
            else cout << "Stan is dishonest" << endl;

            for(int i=0; i<=10; i++) check[i] = false;
        }
    }
}