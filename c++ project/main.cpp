#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(1)
//사용한 알고리즘: 선형탐색, STL MAX, MIN
//사용한 자료구조: 없음

int min_val = 1000000;
int max_val = -1000000;

int n, num;

int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> num;
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    
    cout << min_val << " " << max_val << endl;
}
