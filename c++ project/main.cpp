#include <iostream>

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적계획법 Bottom Up
//사용한 자료구조: 2차원 배열

int d[201][201];
int MOD = 1000000000;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<=n; i++){
        d[i][1] = 1;
        for(int j=0; j<=n; j++){
            for(int h=1; h<=k; h++){
                if(i-j >= 0){
                    d[i][h] = (d[i][h]%MOD + d[j][h-1]%MOD)%MOD;
                    d[i][h] %= MOD;
                }
            }
        }
    }
    
    cout << d[n][k]%MOD << endl;
}
