#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열

int a[1001];
int d[1001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        d[i] = 1;
        int max_val = 0;
        for(int j=0; j<i; j++){
            
            if(a[j] < a[i]){
                max_val = max(d[j], max_val);
            }
        }
        d[i] = max_val + 1;
        
    }
    
    cout << *max_element(d, d+n) <<endl;
    
}

