#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 - Top Down(memoization)
//사용한 자료구조: 배열

long long int d[101][10] = {0};
long long int mod = 1000000000;
long long int result = 0;

long long int go(int n, int j){
    
    if(n == 1){
        return d[1][j];
    }
    
    if(d[n][j] > 0){
        return d[n][j];
    }
    
    if(j == 0){
        d[n][j] = go(n-1, 1);
    }else if(j==9){
        d[n][j] = go(n-1, 8);
    }else{
        d[n][j] = go(n-1, j-1) + go(n-1, j+1);
    }

    d[n][j] %= mod;
    
    return d[n][j];
}


int main(){

    int n;
    cin >> n;

    for(int i=1; i < 10; i++){
        d[1][i] = 1;
    }
    
    for(int j=0; j<10; j++){
        go(n, j);
    }

    for(int i=0; i<10; i++){
        result = (result + d[n][i])%mod;
    }

    cout << result << endl;
    
}
