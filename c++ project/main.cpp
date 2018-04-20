#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, Top-Down
//사용한 자료구조: 2차원 배열

int a[501][501];
int d[501][501];

int go(int i, int j){
    
    if(i<1){
        d[0][0] = a[0][0];
        return d[i][j];
    }
    
    if(d[i][j] > 0){
        return d[i][j];
    }
    
    if(j==0) d[i][j] = a[i][j] + go(i-1, j);
    else if(j==i) d[i][j] = a[i][j] + go(i-1, j-1);
    else d[i][j] = a[i][j] + max(go(i-1, j-1), go(i-1, j));
    
    return d[i][j];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> a[i][j];
        }
    }
    
    int result = 0;
    for(int j=0; j<n; j++){
        result = max(result, go(n-1, j));
    }
    
    cout << result << endl;
}
