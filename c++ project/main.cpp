#include <iostream>
#include <string>
#include <vector>

using namespace std;

string n;
vector<int> result;

void cal_num(int num){
    int cnt = 0;
    while(num > 0){
        result.push_back(num%2);
        cnt++;
        num /= 2;
    }
    if(cnt != 3){
        for(int i=0; i<3-cnt; i++){
            result.push_back(0);
        }
    }
}

int main(){
    cin >> n;
    int size = (int)n.size();
    for(int i=size - 1; i>=0; i--){
        cal_num(n[i] - '0');
    }

    bool startZero = true;
    for(int i=(int)result.size()-1; i>=0; i--){
        if(result[i] == 1){
            startZero = false;
        }
        if(startZero == false){
            printf("%d", result[i]);
        }
    }
    if(result.size() == 3 && result[0] == 0 && result[1] == 0 && result[2] == 0){
        printf("0\n");
    }
}