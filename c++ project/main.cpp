#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top Down
//사용한 자료구조: 1차원 배열

long long int d[101];

long long int go(int i){
    
    if( i <= 6){
        d[i] = i;
        return d[i];
    }
    
    if( d[i] > 0){
        return d[i];
    }
    
    for(int j=3; j<=i-3; j++){
        d[i] = max(d[i], go(i-j) * (j-1));
    }
    
    return d[i];
}


int main() {
    
    int n;
    cin >> n;
    
    cout << go(n) << endl;
    
}
