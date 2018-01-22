#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    int cnt = 1;
    int time = 0;

    while(n>0){

        if(n<cnt){
            cnt = 1;
        }
        n = n - cnt;
        cnt++;
        time++;
    }
    cout << time << endl;
}
