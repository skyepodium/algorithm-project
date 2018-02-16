#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Top-Down
//사용한 자료구조: 1차원 배열

int d_left[1001];
int d_right[1001];
int a[1001];
int n;

int go_left(int n){
    
    if(d_left[n] > 0){
        return d_left[n];
    }

    int max_length = 0;
    for(int i=1; i<n; i++){
        if(a[n] > a[i]){
            max_length = max(max_length, d_left[i]);
        }
    }
    
    d_left[n] = max_length + 1;
    return d_left[n];
}

int go_right(int b){
    
    if(d_right[b] > 0){
        return d_right[b];
    }
    
    int max_length = 0;
    for(int i=n; i>b; i--){
        if(a[b] > a[i]){
            max_length = max(max_length, d_right[i]);
        }
    }
    
    d_right[b] = max_length + 1;
    return d_right[b];
}

int main(){
    

    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=n; i++){
        go_left(i);
    }
    
    for(int i=n; i>=1; i--){
        go_right(i);
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        result = max(result, d_left[i] + d_right[i] - 1);
    }
    
    cout << result << endl;
    
}
