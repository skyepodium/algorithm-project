#include <iostream>

using namespace std;

//시간 복잡도: O(logn)
//공간 복잡도: O(1)
//사용한 알고리즘: 반복문
//사용한 자료구조: 없음

int solution(int n)
{
    int answer = 0;
    while(n != 0){
        if(n%2==0){
            n = n/2;
        }
        else{
            n = n-1;
            answer++;
        }
    }
    return answer;
}