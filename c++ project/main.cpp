#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom-Up
//사용한 자료구조: 1차원 배열

int d[11];

int main(){
    
    int t;
    cin >> t;
    
    vector<int> v(t);
    
    for(int i=0; i<t; i++){
        cin >> v[i];
    }
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    
    for(int i=4; i<=11; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    
    for(int i=0; i<v.size(); i++){
        cout << d[v[i]] << endl;
    }
    
}
