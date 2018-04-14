#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//시간 복잡도: O(2^n)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 재귀함수
//사용한 자료구조: 2차원 배열

int d[16][16];
int n;
int result = 999999999;

void cal_power(vector<int> &left, vector<int> &right){
    
    int left_power = 0;
    int right_power = 0;
    
    for(int i=0; i<n/2; i++){
        for(int j=i+1; j<n/2; j++){
            left_power = left_power + d[left[i]][left[j]] + d[left[j]][left[i]];
            right_power = right_power + d[right[i]][right[j]] + d[right[j]][right[i]];
        }
    }
    
    result = min(result, abs(left_power - right_power));
}

void go(int index, vector<int> &left, vector<int> & right){

    if(index == n){
        if(left.size() == n/2 && right.size() == n/2){
            cal_power(left, right);
        }
        return;
    }

    left.push_back(index);
    go(index+1, left, right);
    left.pop_back();
    
    right.push_back(index);
    go(index+1, left, right);
    right.pop_back();
    
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        result = 999999999;
        cin >> n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
        
        vector<int> left;
        vector<int> right;
        go(0, left, right);
        
        cout << "#" << test_case << " " << result << endl;
        
    }
    return 0;
}
