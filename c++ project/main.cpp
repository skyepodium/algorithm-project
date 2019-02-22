#include <iostream>
#include <vector>

#define max_int 102
using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 인접 리스트

int t, n;
struct info{
    int x;
    int y;
};

// 간선의 정보를 저장하는 인접 리스트
vector<int> v[max_int];
// 정점 방문 여부를 저장할 배열
bool check[max_int];

// 완전 탐색
void dfs(int node){
    check[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

// 맨해튼 거리 계산 함수
int cal_dist(int x1, int y1, int x2, int y2){
    int dist = abs(max(x1, x2) - min(x1, x2)) + abs(max(y1, y2) - min(y1, y2));

    return dist <= 1000 ? true : false;
}

// 변수 초기화 함수
void init(){
    for(int i=0; i<n+2; i++){
        check[i] = false;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case<=t; test_case++){

        scanf("%d", &n);

        // 1. 초기화
        init();

        // 2. 정점의 x좌표, y좌표를 벡터에 입력받습니다.
        vector<info> node(n+2);
        for(int i=0; i<n+2; i++){
            scanf("%d %d", &node[i].x, &node[i].y);
        }

        // 3. 이중 for문으로 모든 간선을 검사해서
        // 1) 두 정점 사이를 이동할 수 있으면 간선을 만들고,
        // 2) 이동 할 수 없으면 간선을 만들지 않습니다.
        for(int i=0; i<n+2; i++){
            for(int j=i+1; j<n+2; j++){

                bool dist = cal_dist(node[i].x, node[i].y, node[j].x, node[j].y);

                if(dist){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }

        // 4. 완전 탐색 수행
        dfs(0);

        // 5. 출력
        // 1) 페스티벌 정점에 도착할 수 있으면 happy 출력
        if(check[n+1]){
            printf("happy\n");
        }
        // 2) 페스티벌 정점에 도착할 수 없으면 sad 출력
        else{
            printf("sad\n");
        }
    }
}