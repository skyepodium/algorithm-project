#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top Down
//사용한 자료구조: 1차원 배열

long long int d[101];

long long int go(int n){
    
    if(n < 5){
        return d[n];
    }
    
    if(d[n] > 0){
        return d[n];
    }
    
    d[n] = go(n-1) + go(n-5);
    
    return d[n];
}



int main(){
    
    int t;
    cin >> t;
    
    d[0] = 0;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;

    go(100);
    
    while(t--){
        int a;
        cin >> a;
        cout << d[a] << endl;
    }
    
}

