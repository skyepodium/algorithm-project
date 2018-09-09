#include <iostream>
#include <algorithm>
#define max_int 21

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 동적 계획법, Bottom_Up
//사용한 자료구조: 1차원, 2차원 배열

/*
 0/1 knapsack 문제
 점화식 설명
 d[i][j] = max(d[i-1][j], d[i-1][j+health[i] + joy[i]);
 d[i][j]는 i번재 사람에게 왔을 때 얻을 수 있는 최대 기쁨(인사하든, 안하든), j는 남은 체력
 
 d[i-1][j]는 i번째 사람에게 왔을때 인사 안하는 경우
 d[i-1][j + health[i]] + joy[i]는 i번째 사람에게 인사하고 joy[i]를 얻는 경우
 j가 남은 체력이기 때문에 i-1번째 사람일떼 j+health[i]만큼 가지고 있어야
 i번째에 왔을때 남은 체력이 j가 된다.
 ex) d[2][78] = d[1][99] + 30
 */

int health[max_int];
int joy[max_int];
int d[max_int][101];
int n;

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", &health[i]);
    for(int i=1; i<=n; i++) scanf("%d", &joy[i]);

    //1. 첫번째 사람에게 인사하고 얻는 기쁨을 초기화 해준다.
    d[1][100-health[1]] = joy[1];
    
    //2. 점화식을 실행한다.
    for(int i=2; i<=n; i++){
        for(int j=100; j>0; j--){
            
            //1) 남은 체력이 health[i]보다 커서 인사할 수 있는 경우
            if(j + health[i] <= 100){
                d[i][j] = max(d[i-1][j], d[i-1][j+health[i]] + joy[i]);
            }
            
            //2) 남은 체력이 health[i]보다 작아서 인사를 할 수 없는 경우
            else{
                d[i][j] = max(d[i-1][j], d[i][j]);
            }
        }
    }
    
    //3. 결과 출력
    //가장 큰 값은 n번째 사람까지 왔을때 1~100까지의 체력을 가진 경우 중 하나이다.
    int result = 0;
    for(int j=1; j<=100; j++){
        result = max(result, d[n][j]);
    }
    
    printf("%d\n", result);
    
    return 0;
}


