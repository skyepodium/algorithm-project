#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-Down
//사용한 자료구조: 1차원 배열

int a[100001];
int d[100001];

int go(int n){
    
    if(n<2){
        d[1] = a[1];
        return d[1];
    }
    
    if(d[n] > 0){
        return d[n];
    }
    
    d[n] = max(go(n-1)+a[n], a[n]);
    
    return d[n];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    go(n);
    
    cout << *max_element(d+1, d+1+n) << endl;
}
