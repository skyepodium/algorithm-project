#include <iostream>
#include <vector>
#include <queue>

#define max_int 100001

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 위상 정렬
//사용한 자료구조: 인접 리스트

int t, n, num, result;
// 정점 i의 indegree 수를 저장하는 배열
// ind[i]=j, 정점i의 indegree수는 j다.
int ind[max_int];
// 간선의 정보를 저장하는 인접 리스트
vector<int> v[max_int];

// 변수 초기화
void init(){
    result = 0;
    for(int i=0; i<=n; i++){
        ind[i] = 0;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);

    // 1. 입력
    for(int test_case=1; test_case <= t; test_case++){
        scanf("%d", &n);

        // 2. 초기화
        init();

        // 3. 간선을 인접리스트에 저장
        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            v[i].push_back(num);
            // indegree의 수를 갱신해준다.
            ind[num]++;
        }

        // 4. 큐에 들어간다는 의미는 사이클에 속하지 않는다는 의미다.
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(ind[i] == 0){
                q.push(i);
                result++;
            }
        }

        // 5. 위상 정렬 수행
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<v[node].size(); i++){
                int next = v[node][i];

                // indegree를 감소시켜준다.
                ind[next]--;

                // indegree가 0이 되면 큐에 넣어준다.
                // 큐에 들어간다는 의미는 사이클에 속하지 않는다는 의미다.
                if(ind[next] == 0) {
                    q.push(next);
                    result++;
                }
            }
        }

        // 6. 출력
        printf("%d\n", result);
    }
}