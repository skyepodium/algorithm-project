#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-Down
//사용한 자료구조: 1차원 배열

int d[1001];
int a[1001];

int go(int n){
    
    if(d[n] > 0){
        return d[n];
    }
    
    int max_length = 0;
    for(int j=1; j<n; j++){
        if(a[j] > a[n]){
            max_length = max(max_length, d[j]);
        }
    }
    
    d[n] = max_length + 1;
    return d[n];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    

    for(int i=1; i<=n; i++){
        go(i);
    }

    cout << *max_element(d+1, d+1+n) << endl;
}
