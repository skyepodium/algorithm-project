#include <string>
#include <vector>
#define max_int 501

using namespace std;
/*
    시간 복잡도: O(n^2)
    공간 복잡도: O(n^2)
    사용한 알고리즘: DP(top-down)
    사용한 자료구조: 2차원 배열
*/


int answer, height, a[max_int][max_int], d[max_int][max_int];

int max(int a, int b){
    return a > b ? a : b;
}

int go(int i, int j){
    
    // 예외 사례 (0, 0)일 경우 현재의 값을 반환한다.
    if(i == 0 && j == 0) return d[i][j];
    
    // 메모이제이션, 이미 계산한 결과일 경우, 저장된 값을 반환한다.
    if(d[i][j] > 0) return d[i][j];
    
    for(int j=0; j<=i; j++){
        // 1) 삼각형 제일 왼쪽 끝인 경우
        if(j == 0){
            d[i][j] = go(i-1, j) + a[i][j];
        // 2) 삼각형 제일 오른쪽 끝인 경우
        }else if(j == i){
            d[i][j] = go(i-1, j-1) + a[i][j];
        }
        // 3) 삼각형 왼쪽, 오른쪽 끝인 아닌 내부인 경우
        else{
            d[i][j] = max(go(i-1, j-1), go(i-1, j)) + a[i][j];
        }
    }
    return d[i][j];
}

int solution(vector<vector<int>> triangle) {
    // 예외 사례, 초기값을 설정해준다.
    d[0][0] = triangle[0][0];
    // 삼각형의 높이를 계산한다.
    height = (int)triangle.size();
    
    /*
     최대 500 * 500인 벡터를 재귀호출때 마다 인자값으로 넣어주면 시간초과 걸린다.
     전역변수에 넣어주었다.
     */
    for(int i=0; i<height; i++){
        for(int j=0; j<=i; j++){
            a[i][j] = triangle[i][j];
        }
    }
    
    // 제일 아래층에 대해서 재귀호출을 수행한다.
    for(int j=0; j<height; j++){
        answer=max(answer, go(height - 1, j));
    }
        
    return answer;
}
