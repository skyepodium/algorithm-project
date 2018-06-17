#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 정렬
//사용한 자료구조: 1차원 벡터

int main(){
    
    long long int diff =  2147483647;
    long long int a = 0;
    long long int b = 0;
    
    int n;
    cin >> n;

    vector<long long int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    diff = v[1] - v[0];
    a = v[0];
    b = v[1];
    
    for(int i=1; i<n-1; i++){
        long long int cal_diff = v[i+1] - v[i];
        
        if(cal_diff < diff){
            a = v[i];
            b = v[i+1];
            diff = cal_diff;
        }
        
    }
    
    cout << a << " " << b << endl;
}
