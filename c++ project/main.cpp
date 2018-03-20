#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom up
//사용한 자료구조: 1차원 배열

int d[1001];
int t[1001];
int p[1001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> t[i];
        cin >> p[i];
    }
    
    for(int i=1; i<=n; i++){
        d[i] = p[i];
        for(int j=1; j<i; j++){
            if(i-j >= t[j]){
                d[i] = max(d[i], d[j] + p[i]);
            }
        }
    }
    
    
    int result = 0;
    for(int i=1; i<=n; i++){
        if(n+1-i >= t[i]){
            result = max(result, d[i]);
        }
    }
    
    cout << result << endl;
    
}

