#include <iostream>
#include <vector>
#include <algorithm>

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 완전탐색, next_permutation
//사용한 자료구조: 1차원 벡터

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    if(next_permutation(v.begin(), v.end())){
        for(int i=0; i<n; i++){
            cout << v[i] <<" ";
        }
    }else{
        cout << -1;
    }
    
    cout << endl;
}
