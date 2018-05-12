#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n+m)
//사용한 알고리즘: 동적 계획법 Bottom up
//사용한 자료구조: 1차원 배열

int d[10001];
int a[21];

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n;
        
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        
        cin >> m;
        
        d[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=a[i]; j<=m; j++){
                d[j] += d[j-a[i]];
            }
        }
        cout << d[m] << endl;
        
        for(int i=0; i<=m; i++){
            d[i] = 0;
        }
    }
    
}
