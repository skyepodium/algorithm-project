#include <iostream>
#define lld long long int
#define max_int 10001

using namespace std;

/*
 시간 복잡도: O(n)
 공간 복잡도: O(n)
 사용한 알고리즘: CCW
 사용한 자료구조: 배열
*/

int n;
lld result;

// 점의 좌표 x, y를 받을 구조체 정의
// 좌표는 int범위이지만, 계산 과정중 int범위를 넘어갈 수 있기 때문에 long long int를 사용했습니다.
struct info{
    lld x, y;
};

// point 배열에는 다각형의 좌표를 저장합니다.
// origin에는 다각형의 가장 첫 좌표를 저장합니다.
info point[max_int], origin;

// CCW 계산
// ccw(즉, 벡터의 외적)의 결과는 두 벡터가 이루는 평행사변형의 면적입니다.
lld ccw(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    return result;
}

int main(){
    // 1. 입력
    scanf("%d", &n);
    
    // 배열에 좌표를 순서대로 입력받습니다.
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &point[i].x, &point[i].y);
    }
    
    // 가장 첫번째 입력받은 점이 기준입니다.
    // 이 점을 기준으로 벡터의 외적을 수행합니다.
    origin = point[1];
    
    // 2. ccw 계산
    // 점을 순서대로 순회하면서 ccw 결과를 더해줍니다.
    for(int i=2; i<=n-1; i++){
        lld ccw_result = ccw(origin, point[i], point[i+1]);
        result += ccw_result;
    }
    
    // 3. 결과
    // ccw 결과가 음수일 수도 있습니다. 이때는 양수로 만들어줍니다.
    if(result < 0) result *= -1;
    
    // ccw의 결과는 평행사변형의 면적이기 때문에 절반으로 나눠서 삼각형의 면적으로 바꿔주었습니다.
    printf("%lld.", result / 2);
    
    // 제일 힘들었던 부분
    // 2로 나누었을때 나머지가 있다는 것은 무조건 소수점 첫번째 자리가 5입니다. 두번째 자리는 없습니다.
    if(result % 2 == 0) printf("0\n");
    else printf("5\n");
}

