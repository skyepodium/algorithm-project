#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    int result=1;
    int addNum = 6;
    int maxNum = 1;
    while(true){
        if(n <= maxNum){
            break;
        }else{
            maxNum = maxNum+ addNum;
            addNum = addNum + 6;
            result++;
        }
    }
    
    cout << result <<endl;
}



