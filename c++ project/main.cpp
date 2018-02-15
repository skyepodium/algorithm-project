#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom-Up
//사용한 자료구조: 2차원 배열

int d[100001][3];
int a[100001][3];

int go(int n, int i){
    
    if(n<2){
        return a[n][i];
    }
    
    if(d[n][i] > 0){
        return d[n][i];
    }
    
    if(i==0) d[n][i] = max(go(n-1, 0), max(go(n-1, 1), go(n-1, 2)));
    else if(i==1) d[n][i] = max(go(n-1, 0), go(n-1, 2)) + a[n][1];
    else d[n][i] = max(go(n-1, 0), go(n-1, 1)) + a[n][2];
    
    return d[n][i];
}


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin >> a[j][i];
            }
        }
        

        d[1][0] = 0;
        d[1][1] = a[1][1];
        d[1][2] = a[1][2];
        cout << max(go(n, 0), max(go(n, 1), go(n,2))) << endl;
        
        for(int i=0; i<=2; i++){
            for(int j=1; j<=n; j++){
                d[j][i] = 0;
            }
        }
        
    }

}
