#include <iostream>
#include <algorithm>

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 그리디 알고리즘
//사용한 자료구조: 1차원 배열

using namespace std;

int a[5] = {100, 50, 30, 10, 1};
int d[5000];
int cnt = 0;

int main(){

    int n;
    cin >> n;
    
    for(int i=0; i<5; i++){
        
        while(n>=a[i]){
            n = n - a[i];
            cnt++;
        }
        
    }
    
    cout << cnt << endl;
    
}
