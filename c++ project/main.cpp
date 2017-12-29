#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 - Top Down
//사용한 자료구조: 배열

int d[1001][10] = {0};
int mod = 10007;
int result = 0;

int go(int n, int j){
    
    if(n == 1){
        return d[1][j];
    }
    
    if(d[n][j] > 0){
        return d[n][j];
        
    }

    for(int k=0; k<=j; k++){
        d[n][j] += go(n-1, k);
        d[n][j] %= mod;
    }
    
    
    return d[n][j];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++){
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
