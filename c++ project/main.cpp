#include <iostream>
#include <vector>
#include <queue>
// 저는 보통 최대값 + 1을 매크로를 사용해서 선언해줍니다.
// 똑같은 숫자 반복사용하면 오타날때도 있고해서요
// 1증가 시키는 이유는 인덱스 참조하다가 실수 날 수 있어서
#define max_int 10001

using namespace std;  

// 저는 보통 다음과 같이 4개의 정보를 주석으로 간단하게 작성해줍니다.
// 그냥, 내가 뭘 만들었는지는 알아먹을수 있어야해서요, 설명할 수는 있어야하잖아요

/*
 시간 복잡도: O(n+m)
 공간 복잡도: O(n)
 사용한 알고리즘: BFS(너비 우선 탐색)
 사용한 자료구조: 인접 리스트, 배열
 */

// check는 최단 거리를 저장할 배열입니다.
int n, m, k, a, b, check[max_int], from[max_int];

// 간선의 정보를 저장할 인접 리스트를 vector로 생성합니다.
vector<int> v[max_int];

// 너비 우선 탐색
void bfs(){
    // 큐를 만들어 줍니다.
    queue<int> q;
    // 시작점까지의 최단 거리는 0입니다.
    check[k] = 0;
    // 큐에 시작점을 넣어줍니다.
    q.push(k);
    
    // 큐가 비어있을때 까지 계속해줍니다.
    // 큐가 비었다는 의미는 시작점에 연결된 모든 다른 정점들을 방문했다는 의미입니다.
    while(!q.empty()){
        // 큐에서 가장 앞에있는것의 정보를 넣어줍니다.
        int node = q.front();
        // 큐 앞에 있는것 비워주는것 꼭 잊지말고요, 빼먹으면, 무한히 돌거에요
        q.pop();
        
        
        // 여기거 중요, 처음에는 낯설어요
        // 임의의 정점에서 연결되 다른 모든 정점들을 next에 넣습니다.
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            // 만약 방문하지 않았다면
            if(check[next] == -1){
                // 여기도 중요! 반드시, 큐에 넣기 전에 방문했음을 체크해줍니다.
                // 여기서 체크안하면 다른 정점이 또 여기를 방문할 수 있습니다.
                // 문제의 예시에서 2 5, 3 5 인데, 2가 먼저 5를 방문했는데 표시 안해주면 3이 또 5를 큐에 넣습니다.
                
                // 간선을 타고 이동할때 마다 1 증가 시키기 때문에 이전 정점까지의 거리에 1을 더해줍니다.
                check[next] = check[node] + 1;
                // 이전 정점의 정보를 from배열에 넣어줍니다.
                from[next] = node;
                // 다음 정점을 큐에 넣어줍니다.
                q.push(next);
            }
        }
    }
}

void tracing(int node){
    if(node == k) return;
    int next = from[node];
    tracing(next);
    printf("%d ", next);
}

int main(){
    // 1. 입력
    // n 정점의 수, m 간선의 수, k 시작점의 번호를 입력 받습니다.
    scanf("%d %d %d", &n, &m, &k);
    
    // 2. 초기화
    // 거리 정보를 저장할 check 배열을 -1로 초기화합니다.
    // 무엇으로 초기화 할지는 개인의 취향입니다.
    for(int i=0; i<=n; i++) check[i] = -1;
    
    // 3. 간선 저장
    for(int i=0; i<m; i++){
        // 간선의 정보를 입력받고
        scanf("%d %d", &a, &b);
        // 중요, 단 방향그래프를 양방향 그래프로 만들어줍니다.
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // 4. 너비 우선 탐색 수행
    bfs();
    
    // 5. 출력
    for(int i=1; i<=n; i++){
        // 1) 시작점인 경우
        if(i == k){
            printf("%d\n", i);
        }
        // 2) 시작점이 아닌 경우
        else{
            // 방문 할 수 있는 경우
            if(check[i] != -1){
                tracing(i);
                printf("\n");
            }
            // 방문 할 수 없는 경우
            else{
                printf("%d\n", -1);
            }
        }
    }
}
