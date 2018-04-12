#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(2^n)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 재귀함수
//사용한 자료구조: 2차원 배열

int n;
int d[20][20];
int result = 1000000;


//힘 차이 계산
void cal_power_diff(vector<int> &left, vector<int> &right){
    
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

//call by reference를 써서 시간 아끼자
//조합을 구한다.
void go(int index, vector<int> &left, vector<int> &right){
    
    if(index == n){
        
        if(left.size() == n/2 && right.size() == n/2){
            
            cal_power_diff(left, right);
            
        }
        
        return;
    }
    
    
    //이번 원소 왼쪽에 포함
    left.push_back(index);
    go(index+1, left, right);
    left.pop_back();
    
    //이번 원소 오른쪽에 포함
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
        result = 1000000;
        cin >> n;
        
        //문제는 1~n인데 나는 0~n을 넣었다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
        
        vector<int> left, right;
        
        go(0, left, right);
        
        cout << "#" << test_case << " " << result << endl;
        
        
        
    }
    return 0;
}
