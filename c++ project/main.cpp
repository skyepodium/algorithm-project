#include <iostream>

using namespace std;

//시간 복잡도: O(1)
//공간 복잡도: O(n)
//사용한 알고리즘: 선형 탐색
//사용한 자료구조: 1차원 배열

//각 월별 날짜수 배열에 저장
int day[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        //첫쨋날 날짜수 계산
        int first_day = day[a-2] + b;
        
        //둘쨋날 날짜수 계산
        int second_day = day[c-2] + d;
        
        //날짜수 차이 출력
        cout << "#" << test_case << " " << second_day - first_day + 1<< endl;
        
    }
    return 0;
}
