#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-down
//사용한 자료구조: 2차원 배열

int d[2][100001];
int a[2][100001];

int go(int i, int j){
    
    if(j<2){
        return d[i][j];
    }
    
    if(d[i][j] >= 0){
        return d[i][j];
    }
    
    if(i==0) d[0][j] = max(go(1, j-1), go(1, j-2)) + a[0][j];
    else d[1][j] = max(go(0, j-1), go(0, j-2)) + a[1][j];
    
    return d[i][j];
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
                d[i][j] = -1;
            }
        }
        
        d[0][0] = a[0][0];
        d[1][0] = a[1][0];
        d[0][1] = d[1][0] + a[0][1];
        d[1][1] = d[0][0] + a[1][1];
        
        printf("%d\n", max(go(0, n-1), go(1, n-1)));
        
    }
    
    
}

