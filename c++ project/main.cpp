#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//시간 복잡도: O(t)
//공간 복잡도: O(t)
//사용한 알고리즘: 정렬
//사용한 자료구조: 1차원 벡터

int main(){
    
    int t;
    cin >> t;

    for(int k=1; k<=3; k++){
    
        vector<int> v(3);
        for(int i=0; i<3; i++){
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        
        int result = 0;
        for(int i=1; i<3; i++){
            if(v[1] != v[i]){
                result = v[i];
            }
        }
        
        if(result == 0){
            cout << '#'<<k<<" "<<v[0] << endl;;
        }else{
            cout << '#'<<k<<" "<<result << endl;
        }
    }
}
