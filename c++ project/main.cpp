#include <iostream>
#include <vector>
#include <queue>

#define max_val 2000005;
#define max_int 201
using namespace std;

//시간 복잡도: O(n^2logm)
//공간 복잡도: O(m)
//사용한 알고리즘: 다익스트라 알고리즘, 경로 추척
//사용한 자료구조: 인접 리스트

int n, m, a, b, c;
// 정점 i까지의 거리 정보를 담는 배열
// d[i] = l, 시작 정점에서 정점 i까지 가는 시간은 l
int d[max_int];
struct info{
    int cur;
    int cost;
};

// 간선의 정보를 저장하는 인접 리스트
vector<info> v[max_int];

// c++의 priority_queue는 max_heap이기 때문에 min_heap으로 바꿔줍니다.
struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

// 경로 추적을 위한 배열, p[i] = j, 정점 j에서 정점 i로 왔습니다.
int p[max_int];

int main(){
    scanf("%d %d", &n, &m);

    // 1. 간선 정보 입력
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    // 2. n개의 정점에 대해 다익스트라 알고리즘 수행

    // 1) 우선순위 큐 생성
    priority_queue<info, vector<info>, cmp> pq;
    for(int start_node=1; start_node <= n; start_node++){

        // 2) 거리 정보 초기화
        for(int i=1; i<=n; i++) d[i] = max_val;
        d[start_node] = 0;
        pq.push({start_node, 0});

        while(!pq.empty()){
            info cur = pq.top();
            int c_node = cur.cur;
            pq.pop();

            for(int i=0; i<v[c_node].size(); i++){
                info next = v[c_node][i];
                int n_node = next.cur;
                int n_cost = next.cost;

                if(d[n_node] > d[c_node] + n_cost){
                    d[n_node] = d[c_node] + n_cost;
                    // 경로 정보를 갱신합니다.
                    // p[n_node] = c_node의 의미는 c_node에서 n_node로 왔습니다.
                    p[n_node] = c_node;
                    pq.push({n_node, d[n_node]});
                }
            }
        }

        // 3. 경로표 출력
        for(int i=1; i<=n; i++){
            // 1) 시작 정점이면 - 출력
            if(i==start_node){
                printf("- ");
            }
            // 2) 바로 이전 정점이 시작 정점이면, 현재 정점 출력
            else if(p[i] == start_node){
                printf("%d ", i);
            }
            // 3) 경로 추척
            else{
                int cur_node = i;
                while(true){
                    // 시작 정점 바로 이전까지 검사합니다.
                    if(p[cur_node] == start_node){
                        printf("%d ", cur_node);
                        break;
                    }else{
                        cur_node = p[cur_node];
                    }
                }
            }
        }
        printf("\n");
    }
}