#include <iostream>
#include <algorithm>

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열

using namespace std;

int a[5] = {1, 10, 30, 50, 100};
int d[5000];

int main(){

    int n;
    cin >> n;
    
    d[0] = 0;
    
    for(int i=1; i<=n; i++){
        int min_val = 5000;
        
        for(int j=0; j<5; j++){
            if(i - a[j] >=0){
                min_val = min(min_val, d[i-a[j]] + 1);
            }
        }
        d[i] = min_val;
    }
    
    cout << d[n] << endl;
    
}
