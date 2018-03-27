#include <iostream>

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적계획법 Top Down
//사용한 자료구조: 2차원 배열

int d[201][201];
int MOD = 1000000000;

int n, k;

int go(int i, int h){
    
    if(h==1){
        d[i][1] = 1;
    }
    
    if(d[i][h] > 0){
        return d[i][h];
    }
    
    for(int j=0; j<=n; j++){
        if(i-j >= 0){
            d[i][h] = (d[i][h]%MOD + go(j, h-1)%MOD)%MOD;
            d[i][h] %= MOD;
        }
    }
    
    return d[i][h]%MOD;
}


int main(){
    
    
    cin >> n >> k;
    
    cout << go(n, k)%MOD << endl;
}


