#include <string>
#include <vector>

using namespace std;

/*
    시간 복잡도: O(n^2)
    공간 복잡도: O(n)
    사용한 알고리즘: 쉬프트 연산
    사용한 자료구조: 배열
*/


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    // n개의 숫자에 대해 n번 반복합니다.
    for(int i=0; i<n; i++){
        // 결과를 문자열로 저장할 변수 num
        string num = "";

        // 배열 요소의 최대 크기는 2^n - 1, 최대 n개의 비트를 가지고 있습니다.
        for(int j=n-1; j>=0; j--){

            // 1. arr1, arr2의 n 번째 비트가 하나라도 1인 경우
            if((arr1[i] & (1 << j)) | (arr2[i] & (1 << j))){
                num += "#";
            }
            // 2. arr1, arr2의 n 번째 비트가 모두 0인 경우
            // (if문의 조건에 0이 들어오면 false로 인식합니다.)
            else{
                num += " ";
            }
        }
        answer.push_back(num);
    }

    return answer;
}