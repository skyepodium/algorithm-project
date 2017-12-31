#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법
//사용한 자료구조: 배열

int d[10001];
int a[101];

int main(){
    
    int n, k;
    cin >> n >> k;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=a[i]; j<=k; j++){
            d[j] += d[j-a[i]];
        }
    }

    cout << d[k] << endl;
    
}
