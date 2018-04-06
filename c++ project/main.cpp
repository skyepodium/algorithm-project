#include <iostream>

using namespace std;

int a[101][101];
long long d[101][101];

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, Top Down
//사용한 자료구조: 2차원 배열

int n;

void clear_array(){
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = 0;
        }
    }
    
}

long long int go(int i, int j){

    if(i==1 && j==1){
        d[1][1] = 1;
        return d[i][j];
    }
    
    if(d[i][j] > 0){
        return d[i][j];
    }
    
    for(int k=1; k<j; k++){
        if(k+a[i][k] == j) d[i][j] += go(i, k);
    }
    
    for(int k=1; k<i; k++){
        if(k+a[k][j] == i) d[i][j] += go(k, j);
    }
    
    return d[i][j];
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        

        cin >> n;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> a[i][j];
            }
        }
        
        if(go(n, n) > 0) cout << "YES" << endl;
        else cout << "NO" << endl;

        clear_array();
    }

    
}
