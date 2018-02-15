#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Top-Down
//사용한 자료구조: 1차원 배열

int d[1001];
int mod = 10007;

int go(int n){
    
    if(n < 2){
        return 1;
    }
    
    if(d[n] > 0){
        return d[n]%mod;
    }
    
    d[n] = go(n-1)%mod + go(n-2)%mod;
    return d[n]%mod;
}

int main(){

    int n;
    cin >> n;
    
    cout << go(n)%mod << endl;

    
}
