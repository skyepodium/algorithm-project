#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: for문
//사용한 자료구조: 1차원 배열

int num;
int d[1001];
int min_dis;
int result;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        min_dis = 2147483647;
        result = 0;
        
        cin >> num;
        for(int i=0; i<num; i++){
            cin >> d[i];
            min_dis = min(min_dis, abs(d[i]));
        }
        
        for(int i=0; i<num; i++){
            if(min_dis == abs(d[i])) result++;
        }
        
        cout << "#" << test_case << " " << min_dis << " " << result << endl;
    }
    return 0;
}
