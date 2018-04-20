#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Top-Down
//사용한 자료구조: 1차원 배열

int a[1001];
int d[1001];

int go(int i){
    
    if(d[i] > 1){
        return d[i];
    }
    
    int max_val = 0;
    for(int j=0; j<i; j++){
        if(a[j] < a[i]){
            max_val = max(max_val, go(j));
        }
    }
    
    d[i] = max_val + 1;

    return d[i];
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        d[i] = 1;
    }
    
    int result = 0;
    for(int i=0; i<n; i++){
        result = max(result, go(i));
    }
    
    cout << result << endl;
}

