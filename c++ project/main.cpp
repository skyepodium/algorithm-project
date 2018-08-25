#include <iostream>
#include <algorithm>

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom-Up
//사용한 자료구조: 1차원 배열

using namespace std;

int a[1001];
int d[1001];

int go(int i){
    
    if(d[i] > 1){
        return d[i];
    }
    
    for(int j=0; j<i; j++){
        if(a[j] > a[i]){
            d[i] = max(d[i], d[j]+1);
        }
    }
    
    return d[i];
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        d[i] = 1;
    }
    
    for(int i=0; i<n; i++){
        go(i);
    }
    
    cout << *max_element(d, d+n) << endl;
}
