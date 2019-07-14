#include <iostream>
#define max_int 101

using namespace std;

/*
 시간 복잡도: O(1)
 공간 복잡도: O(1)
 사용한 알고리즘: 플레인 스위핑
 사용한 자료구조: 2차원 배열
*/

int n, a[max_int][max_int], x, y, result;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main(){
    
    // 1. 입력
    scanf("%d", &n);
    
    // 색종이의 왼쪽 아래 모서리의 좌표를 입력받습니다.
    for(int k=1; k<=n; k++){
        scanf("%d %d", &x, &y);
        
        // 왼쪽 모서리를 기준으로 색종이의 영역을 모두 1로 채웁니다.
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++){
                a[i][j] = 1;
            }
        }
    }
    
    // 2. 플레인 스위핑
    // x좌표를 0부터 100까지 살펴봅니다.
    for(int j=0; j<max_int; j++){
        // 현재 x좌표에 대해 y좌표를 0부터 100까지 살펴봅니다.
        for(int i=0; i<max_int; i++){
            //현재 좌표가 색종이가 덮지 않았을때를 살펴봅니다
            if(a[i][j] != 0) continue;
            
            //현재 위치에서 4방향을 살펴봅니다.
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                // 4방향을 살폈는데, 색종이가 있으면 둘레를 1 증가시켜줍니다.
                if(nx>=0 && nx<max_int && ny>=0 && ny < max_int){
                    if(a[nx][ny] == 1){
                        result++;
                    }
                }
            }
        }
    }
    
    // 3. 출력
    printf("%d\n", result);
}
