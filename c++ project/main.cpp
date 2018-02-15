#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Top-Down
//사용한 자료구조: 1차원 배열

int d[11];

int go(int n){
    
    if(n < 4){
        return d[n];
    }
    
    if(d[n] > 0){
        return d[n];
    }
    
    d[n] = go(n-1) + go(n-2) + go(n-3);
    
    return d[n];
}


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

    go(10);
    
    for(int i=0; i<v.size(); i++){
        cout << d[v[i]] << endl;
    }
    
}
