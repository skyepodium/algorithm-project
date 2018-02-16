#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-Down
//사용한 자료구조: 2차원 배열

int d[10001][3];
int a[10001];

int go(int n, int i){
    
    if(n < 2){
        return d[n][i];
    }
    
    if(d[n][i] > 0){
        return d[n][i];
    }
    
    if(i==0) d[n][0] = max(go(n-1, 0), max(go(n-1, 1), go(n-1, 2)));
    else if(i==1) d[n][1] = go(n-1, 0) + a[n];
    else d[n][2] = go(n-1, 1) + a[n];
    
    return d[n][i];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[1][0] = 0;
    d[1][1] = a[1];
    
    cout << max(go(n, 0), max(go(n, 1), go(n, 2))) << endl;
}
