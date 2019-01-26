#include <string>
#include <vector>
#include <algorithm>

#define max_int 101
using namespace std;

//시간 복잡도: O(elogn) (n: 정점의 개수, e: 간선의 개수)
//공간 복잡도: O(en)
//사용한 알고리즘: 크루스칼 알고리즘
//사용한 자료구조: 인접리스트


// d[i]는 정점 i의 부모 정점을 넣는다.
int d[max_int];


// find는 최상위 부모를 찾는 함수
int find(int node){
    // 1) 만약 부모가 자기자신이면 현재 노드가 최상위 부모이다.
    if(node == d[node]) return node;

        // 2) 아니라면 최상위 부모의 부모를 찾는다.
    else return d[node] = find(d[node]);
}


// 간선의 가중치를 기준으로 오름차순 정렬
bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 1. d[i] = i의 부모를 담는다. 처음에는 자기 자신이 부모이다.
    // disjoint-set을 사용하기 위해 초기화
    for(int i=0; i<n; i++){
        d[i] = i;
    }


    // 2. 간선의 가중치 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);


    // 3. 모든 간선을 검사한다.
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];


        // 4. start와 end가 아직 연결되지 않았다면
        if(start != end){
            // 1) start의 부모를 end로 설정하고
            d[start] = end;

            // 2) 간선의 가중치를 결과에 더해준다.
            answer += cost;
        }
    }

    return answer;
}