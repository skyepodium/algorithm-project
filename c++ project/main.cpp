#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법 Bottom-Up
//사용한 자료구조: 1차원 배열

int d[1001];
int a[1001];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = 1;
    }
    
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[j] > a[i] && d[j]+1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
    }
    
    cout << *max_element(d+1, d+1+n) << endl;
}
