#include <string>
#include <vector>
#define max_int 501

using namespace std;
/*
    시간 복잡도: O(n^2)
    공간 복잡도: O(n^2)
    사용한 알고리즘: DP(bottom-up)
    사용한 자료구조: 2차원 배열
*/

int max(int a, int b){
    return a > b ? a : b;
}

int answer, height, d[max_int][max_int];

int solution(vector<vector<int>> triangle) {
    // 예외 사례, 초기값을 설정해준다.
    answer = d[0][0] = triangle[0][0];
    // 삼각형의 높이를 계산한다.
    height = (int)triangle.size();
    
    for(int i=1; i<height; i++){
        for(int j=0; j<=i; j++){
            // 1) 삼각형 제일 왼쪽 끝인 경우
            if(j == 0){
                d[i][j] = d[i-1][j] + triangle[i][j];
            // 2) 삼각형 제일 오른쪽 끝인 경우
            }else if(j == i){
                d[i][j] = d[i-1][j-1] + triangle[i][j];
            }
            // 3) 삼각형 왼쪽, 오른쪽 끝인 아닌 내부인 경우
            else{
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
            }
            
            // 최대갑 갱신
            answer = max(answer, d[i][j]);
        }
    }
        
    return answer;
}
