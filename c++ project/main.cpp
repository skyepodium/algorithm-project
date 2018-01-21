#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top Down
//사용한 자료구조: 1차원 배열

int d[1001];
int a[1001];

int go(int i){
    
    if(d[i] > 0) return d[i];
    
    int max_length = 0;
    for(int j=1; j<i; j++){
        
        if(a[i] < a[j]){
            max_length = max(max_length, d[j]);
        }
    }
    d[i] = max_length + 1;
    
    return d[i];
}


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        if (result < go(i)){
            result = go(i);
        }
    }
    
    cout << result << endl;
}
