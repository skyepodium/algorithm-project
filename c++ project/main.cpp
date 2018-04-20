#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, bottom-up
//사용한 자료구조: 2차원 배열

int a[501][501];
int d[501][501];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> a[i][j];
        }
    }
    
    d[0][0] = a[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            
            if(j==0) d[i][j] = a[i][j] + d[i-1][j];
            else if(j==i) d[i][j] = a[i][j] + d[i-1][j-1];
            else d[i][j] = a[i][j] + max(d[i-1][j-1], d[i-1][j]);
            
        }
    }
    
    int result = 0;
    for(int j=0; j<n; j++){
        result = max(result, d[n-1][j]);
    }
    
    cout << result << endl;
}
