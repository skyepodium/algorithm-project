#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top down
//사용한 자료구조: 배열

int d[10001];
int a[10001];

int go(int n){
    
    if(n<3){
        return d[n];
    }
    
    if(d[n] > 0){
        return d[n];
    }
    
    d[n] = max(go(n-1), max(go(n-2) + a[n], go(n-3) + a[n-1] + a[n]));
    
    return d[n];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    d[1] = a[1];
    d[2] = a[1] + a[2];
    
    cout << go(n) << endl;
}
