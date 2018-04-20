#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 동적 계획법, bottom-up
//사용한 자료구조: 2차원 배열

//입력 정보를 담을 2차원 배열 a
int a[501][501];

//점화식 계산정보를 담을 2차원 배열 d
int d[501][501];


int main(){
    
    int n;
    cin >> n;
    
    //2차원 배열 a에 삼각형의 정보를 입력받는다.
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> a[i][j];
        }
    }
    
    //점화식을 위해 제일 작은 값 초기화
    d[0][0] = a[0][0];
    
    //1번 행별부터 돌면서 점화식을 계산한다.
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            
            //제일 왼쪽일때
            if(j==0) d[i][j] = a[i][j] + d[i-1][j];
            
            //제일 오른쪽일때
            else if(j==i) d[i][j] = a[i][j] + d[i-1][j-1];
            
            //그외
            else d[i][j] = a[i][j] + max(d[i-1][j-1], d[i-1][j]);
            
        }
    }
    
    //마지막 행에서 최대값을 구한다.
    int result = 0;
    for(int j=0; j<n; j++){
        result = max(result, d[n-1][j]);
    }
    
    cout << result << endl;
}
