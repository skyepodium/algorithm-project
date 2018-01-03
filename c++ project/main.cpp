#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top Down
//사용한 자료구조: 2차원 배열

int d[1001][4];
int a[1001][4];

int go(int n, int j){
    
    if(n<2){//재귀 탈출을 위한 기저사례
        return d[n][j];
    }
    
    if(d[n][j] > 0){//메모이제이션
        return d[n][j];
    }
    
    d[n][1] = min(go(n-1, 2), go(n-1, 3)) + a[n][1];
    d[n][2] = min(go(n-1, 1), go(n-1, 3)) + a[n][2];
    d[n][3] = min(go(n-1, 1), go(n-1, 2)) + a[n][3];
    
    return d[n][j];
}

int main(){

    int n, result = 0;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin >> a[i][j];
        }
    }

    d[1][1] = a[1][1];
    d[1][2] = a[1][2];
    d[1][3] = a[1][3];
    
    result = min(go(n, 1), min(go(n, 2), go(n, 3)));
    cout << result << endl;
}

