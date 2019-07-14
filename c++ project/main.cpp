#include <iostream>
#define lld long long int
using namespace std;

/*
 시간 복잡도: O(1)
 공간 복잡도: O(1)
 사용한 알고리즘: CCW
 사용한 자료구조: 배열
*/

int ccw_result;

// 점을 입력받을 구조체를 정의 합니다.
struct info{
    lld x, y;
};

// 정의한 구조체를 기반으로 배열을 생성합니다.(3개의 점이 주어집니다.)
info point[4];

// CCW
// 세점의 좌표정보를 순서대로 받습니다.
int ccw(info r, info p, info q){
    // 벡터의 외적을 수행합니다.
    // 점 p, q에대해 점 r의 x, y를 빼줘서 그래프를 원점에 맞춥니다.
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    
    // 1) 1 이면 벡터rp 기준 점 q는 왼쪽에 존재합니다.
    if(result > 0) return 1;
    // 2) 0 이면 일직선에 존재
    else if(result == 0) return 0;
    // 3) -1 이면 벡터rp 기준 점 q는 오른쪽에 존재합니다.
    else return -1;
}

int main(){
    //1. 3개의 점을 순서대로 배열에 입력받습니다.
    for(int i=1; i<=3; i++){
        scanf("%lld %lld", &point[i].x, &point[i].y);
    }
    
    // 2. CCW를 수행합니다.
    ccw_result = ccw(point[1], point[2], point[3]);
    
    // 3. 결과 출력
    printf("%d\n", ccw_result);
}
