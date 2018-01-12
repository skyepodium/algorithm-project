#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom up
//사용한 자료구조: 배열

int d[1001];
int d2[1001];
int a[1001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=n; i++){
        d[i] = 1;
        int max_length = 0;
        for(int j=1; j<i; j++){
            if(a[j] < a[i]){
                max_length = max(max_length, d[j]);
            }
        }
        d[i] = max_length + 1;
    }

    for(int i=n; i>0; i--){
        d2[i] = 1;
        int max_length = 0;
        for(int j=n; j>i; j--){
            if(a[i] > a[j]){
                max_length = max(max_length, d2[j]);
            }
        }
        d2[i] = max_length + 1;
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        if(result < d[i] + d2[i] -1){
            result = d[i] + d2[i] -1;
        }
    }
    
    cout << result << endl;
}
