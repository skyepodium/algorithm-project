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

    for(int i=0; i<n; i++){
        string num = "";
        for(int j=n-1; j>=0; j--){
            if(((arr1[i] & (1 << j)) == 0) && ((arr2[i] & (1 << j)) == 0)){
                num += " ";
            }else{
                num += "#";
            }
        }
        answer.push_back(num);
    }

    return answer;
}