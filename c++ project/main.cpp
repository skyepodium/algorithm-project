#include <iostream>

using namespace std;

int main(){
    
    long long int s;
    cin >> s;
    
    long long int cnt = 0;
    while(s>cnt){
        cnt++;
        s = s-cnt;
    }
    cout << cnt << endl;
}


