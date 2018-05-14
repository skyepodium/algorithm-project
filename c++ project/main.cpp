#include <iostream>
#include <algorithm>

int a[5] = {100, 50, 30, 10, 1};
int d[5000];

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        int min_val = 5000;
        for(int j=0; j<5; j++){
            if(i-a[j] >= 0){
                min_val = min(min_val, d[i-a[j]] + 1);
            }
        }
        d[i] = min_val;
        
    }
    
    cout << d[n] << endl;
    
}

