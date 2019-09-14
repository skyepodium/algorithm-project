#include <iostream>
#include <vector>
#include <queue>
#define max_int 101

using namespace std;

/*
 시간 복잡도: O(n^2+nm)
 공간 복잡도: O(n+m)
 사용한 알고리즘: BFS
 사용한 자료구조: 인접 리스트
 
 설명: 정방향, 역방향 BFS를 각각 진행했을때 자신의 순서가 중간번호보다 크다면 중간 숫자가 될 수 없다.
 */

int n, m, a, b, cnt, rcnt, result, baseNum;
bool check[max_int], rcheck[max_int];

// 정방향 간선의 정보를 저장할 인접리스트 v
vector<int> v[max_int];

// 역방향 간선의 정보를 저장할 인접리스트 r
vector<int> r[max_int];

// 정방향 bfs
void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            if(!check[next]){
                check[next] = true;
                cnt++;
                q.push(next);
            }
        }
    }
}

// 역방향 bfs
void rbfs(int start){
    rcheck[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<r[node].size(); i++){
            int next = r[node][i];
            
            if(!rcheck[next]){
                rcheck[next] = true;
                rcnt++;
                q.push(next);
            }
        }
    }
}

// 방문 기록 및 방문 개수 초기화
void clear(){
    cnt = 0;
    rcnt = 0;
    for(int i=1; i<=n; i++){
        check[i] = false;
        rcheck[i] = false;
    }
}

int main(){
    
    // 1. 입력
    scanf("%d %d", &n, &m);
    
    // 2. 간선의 정보를 입력받는다.
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        // 1) 정방향은 인접 리스트 v에 넣고
        v[a].push_back(b);
        
        // 2) 역방향은 인접 리스트 r에 넣는다.
        r[b].push_back(a);
    }
    
    // 3. 무게 순서 중간인 숫자를 계산한다.
    // 예) n이 5일 때 baseNum 은 3이다.
    baseNum = (n+1)/2;
    
    // 4. 각 정점마다 BFS 수행
    for(int i=1; i<=n; i++){
        // 1) 방문 기록 및 방문 개수 초기화
        clear();
        
        // 2) 정방향, 역방향 BFS 각각 돌아준다.
        bfs(i);
        rbfs(i);
        
        // 3) 정방향, 역방향 순회 결과
        // 순서가 중간 번호 보다 크다면, 절대 중간 번호가 될 수 없다.
        if(cnt >= baseNum || rcnt >= baseNum){
            result++;
        }
        
    }
    
    // 5. 출력
    printf("%d\n", result);
}
