#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 - Bottom Up
//사용한 자료구조: 배열

long long int d[101][11] = {0};
long long int mod = 1000000000;
long long int result = 0;

int main(){

    long long int n;
    cin >> n;

    for(int i=1; i < 10; i++){
        d[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][1];
        for(int j=1; j<10; j++){
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%mod;
        }
    }

    for(int i=0; i<10; i++){
        result = (result + d[n][i])%mod;
    }
    
    cout << result << endl;
    
}
