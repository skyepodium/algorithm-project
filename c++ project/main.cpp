#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom up
//사용한 자료구조: 배열

int d[100000][3];
int a[100000][3];

int main(){
    
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin >> a[j][i];
            }
        }

        d[1][0] = 0;
        d[1][1] = a[1][1];
        d[1][2] = a[1][2];
        
        for(int j=2; j<=n; j++){

            d[j][0] = max(d[j-1][0], max(d[j-1][1], d[j-1][2]));
            d[j][1] = max(d[j-1][0], d[j-1][2]) + a[j][1];
            d[j][2] = max(d[j-1][0], d[j-1][1]) + a[j][2];
                
        }

        int result = 0;
        result = max(d[n][0], max(d[n][1], d[n][2]));
        cout << result << endl;
    }
    
}
