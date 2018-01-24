#include <iostream>
#include <algorithm>

using namespace std;


//시간 복잡도: O(nm)
//공간 복잡도: O(nm)
//사용한 알고리즘: 동적 계획법, Bottom up
//사용한 자료구조: 2차원 배열

int a[101][101];
long long int d[101][101];

long long int go(int i, int j){
    
    if(i==1 && j==1){
        return 1;
    }
    
    if(d[i][j] > 0){
        return d[i][j];
    }
    
    for(int k=1; k<j; k++){
        if (k+a[i][k] == j) {
            d[i][j] += go(i, k);
        }
    }
    
    for (int k=1; k<i; k++) {
        if (k+a[k][j] == i) {
            d[i][j] += go(k, j);
        }
    }
    
    return d[i][j];
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    
    cout << go(n, n) << endl;
}


