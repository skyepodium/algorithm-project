#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom-Up
//사용한 자료구조: 2차원 배열

int a[10001];
int d[10001][3];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        cin >> a[i];
    }
    
    d[0][0] = 0;
    d[0][1] = a[0];
    d[0][2] = 0;
    
    for(int i=1; i<n; i++){
        
        d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    
    cout << max(d[n-1][0], max(d[n-1][1], d[n-1][2])) << endl;
    
}
