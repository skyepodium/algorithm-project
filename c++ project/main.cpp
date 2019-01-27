#include <vector>
#include <queue>
#define max_int 51
#define max_val 2500001

using namespace std;

//시간 복잡도: O(ElogN) (N: 정점의 개수 50 이하, E: 간선의 개수 2000이하)
//공간 복잡도: O(EN)
//사용한 알고리즘: 다익스트라 알고리즘
//사용한 자료구조: 인접리스트

// d[i] 는 1번 정점(시작 정점)에서 i번 정점까지 최단 시간
int d[max_int];

struct info{
    int cur;
    int cost;
};

// c++의 우선순위 큐는 max_heap이기 때문에 min_heap으로 바꿔준다.
struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

vector<info> v[max_int];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // 1. 간선의 정보를 인접리스트에 담는다, 양방향 그래프의 정보를 넣어준다.
    for(int i=0; i<road.size(); i++){
        int node = road[i][0];
        int cur = road[i][1];
        int cost = road[i][2];
        v[node].push_back({cur, cost});
        v[cur].push_back({node, cost});
    }

    // 2. 모든 정점까지의 시간을 최대값으로 초기화한다.
    for(int i=1; i<=N; i++) d[i] = max_val;

    // 3. 우선순위 큐를 생성하고, 1번 정점까지의 시간은 0으로 초기화 한다.
    priority_queue<info, vector<info>, cmp> pq;
    d[1] = 0;
    pq.push({1, d[1]});

    // 4. 다익스트라 알고리즘 수행
    while(!pq.empty()){
        // 1) 인접한 정점중 가장 가까운 정점을 선택한다.
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;

        // 2) 현재 정점에서 인접한 정점 검사
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;

            // 3) 만약 현재 정점에서 다음 정점까지 가는 시간이 더 짧으면 시간을 갱신해준다.
            if(d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
                pq.push({n_node, d[n_node]});
            }
        }
    }

    // 5. 해당 정점까지의 시간이 K 이하라면 결과 1증가
    for(int i=1; i<=N; i++){
        if(d[i] <= K) answer++;
    }

    return answer;
}