#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom up
//사용한 자료구조: 2차원 배열

long long int d[301][3];
long long int a[301];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[1][1] = a[1];
    d[1][2] = 0;
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];
    
    for(int i=3; i<=n; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    
    cout << max(d[n][1], d[n][2]) << endl;
}
