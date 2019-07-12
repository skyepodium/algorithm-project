#include <iostream>
#define max_int 10001
#define max_val 1000000001
#define lld long long int

using namespace std;

/*
 시간 복잡도: O(n)
 공간 복잡도: O(n)
 사용한 알고리즘: 레이 캐스팅
 사용한 자료조: 배열
*/

int n;
struct info{
    lld x, y;
};

// point는 정점의 좌표를 저장할 배열
// terror는 대연, 영훈, 범진 3명의 좌표를 저장할 배열
info point[max_int], terror[4], start_point, end_point;

// 함수 오버로딩
bool operator > (info a, info b){
    if(a.x == b.x) return a.y > b.y;
    else return a.x > b.x;
}

// 함수 오버로딩
bool operator <= (info a, info b){
    if(a.x == b.x) return a.y <= b.y;
    else return a.x < b.x;
}

// CCW
int ccw(info r, info p, info q){
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;
    if(result > 0) return 1;
    else if(result == 0) return 0;
    else return -1;
}

// 선분 교차 여부 판단
bool check_cross(info a, info b, info c, info d){
    
    int first = ccw(a, b, c) * ccw(a, b, d);
    int second = ccw(c, d, a) * ccw(c, d, b);
    
    if(first == 0 && second == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        
        // 이 조건을 만족하면 쭉 연장된 같은 직선위에 있고 일부분이 겹친다는 의미
        return a <= d && c <= b;
    }
    else{
        // 이 조건을 만족하면 선분은 교차한다.
        return first <= 0 && second <= 0;
    }
}

int main(){
    
    // 1. 입력
    scanf("%d", &n);
    
    // 1) 정점 입력
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &point[i].x, &point[i].y);
    }
    
    // 대연, 영훈, 범진 3명의 위치 입력
    for(int i=1; i<=3; i++){
        scanf("%lld %lld", &terror[i].x, &terror[i].y);
    }
    
    // 2. 각 사람마다 다각형 내부에 있는지 검사
    // 1) 정점의 수가 3개 이상일 경우
    if (n >= 3) {
        for(int i=1; i<=3; i++){
            start_point = terror[i];
            // 반대쪽 끝점의 x는 입력값으로 존재할 수 없는 x좌표
            end_point.x = max_val;
            // y는 1을 증가시키면, 다른 정점이랑 절대 겹칠일이 없다. (중요)
            end_point.y = terror[i].y + 1;
            
            bool find = false;
            int cnt = 0;
            for(int j=1; j<=n; j++){
                info first = point[j];
                info second = point[j+1];
                if(j == n) second = point[1];
                
                // 사람의 좌표가 정점의 좌표랑 같을 경우에 대한 예외처리
                if(start_point.x == first.x && start_point.y == first.y) find = true;
                else if(start_point.x == second.x && start_point.y == second.y) find = true;
                if(find) {
                    printf("1\n");
                    break;
                }
                
                bool check_result = check_cross(start_point, end_point, first, second);
                if(check_result){
                    cnt++;
                }
            }
            if(find) continue;
            if(cnt % 2 == 0) printf("%d\n", 0);
            else printf("%d\n", 1);
        }
    }
    // 정점의 수가 2개 이하일 경우 예외처리
    else{
        for(int i=1; i<=n; i++){
            printf("0\n");
        }
    }
}
