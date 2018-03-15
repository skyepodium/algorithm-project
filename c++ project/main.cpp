#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(n+40)
//공간 복잡도: O(n)
//사용한 알고리즘: for문
//사용한 자료구조: 벡터

vector<pair<int, int>> v;

int main(){
    
    v.push_back(make_pair(1, 0));
    
    for(int i=1; i<41; i++){
        int first = v.back().second;
        int second = v.back().first + v.back().second;
        v.push_back(make_pair(first, second));
    }


    int t;
    cin >> t;
    while(t--){
        
        int num;
        cin >> num;
        cout << v[num].first << " " << v[num].second << endl;
    }
    
    
}
