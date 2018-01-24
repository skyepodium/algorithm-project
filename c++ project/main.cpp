#include <iostream>

using namespace std;

int a[101][101];
long long d[101][101];

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, Bottom up
//사용한 자료구조: 2차원 배열

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    
    d[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == 1 && j == 1) continue;
            
            for (int k=1; k<j; k++) {
                if (k+a[i][k] == j) {
                    d[i][j] += d[i][k];
                }
            }

            for (int k=1; k<i; k++) {
                if (k+a[k][j] == i) {
                    d[i][j] += d[k][j];
                }
            }
        }
    }
    
    cout << d[n][n] << endl;
}
