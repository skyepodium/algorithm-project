#include <iostream>
#include <queue>

#define max_int 300001
using namespace std;

// 시간 복잡도: O(n)
// 공간 복잡도: O(n)
// 사용한 알고리즘: BFS
// 사용한 자료구조: 1차원 배열

int t, n;

// check 배열을 개체 수를 만드는데 필요한 최소 시간을 저장합니다.
// check[i] = a라고 하면, 개체 수 i를 만들기 위한 시간 a를 의미합니다.
int check[max_int];

// BFS 탐색
void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        int next;
        q.pop();

        // 1) 분열 성공
        next = node * 2;
        // 다음 만들려고 하는 개체 수가 30만 이하일 때
        // 분열을 실패해서 30만에서 10만으로 올 수도 있습니다.
        if(next < max_int){
            // 아직 해당 개체 수를 만들지 않았다면, 만들어줍니다.
            // -1로 초기화했기 때문에 check[i] = -1이면 아직 해당 개체 수를 만들지 않은 것입니다.
            if(check[next] == -1){
                // 해당 개체 수를 만드는 시간은 현재 개체 수를 만드는 시간 + 1초
                check[next] = check[node] + 1;
                q.push(next);
            }
        }

        // 2) 분열 실패
        next = node/3;
        // 다음 만들려고 하는 개체 수가 1이상일 때
        // 개체 수가 1일 때는 이미 만들었고, 최소 개체수는 1입니다.
        if(next >= 1){
            // 아직 해당 개체 수를 만들지 않았다면, 만들어줍니다.
            // -1로 초기화했기 때문에 check[i] = -1이면 아직 해당 개체 수를 만들지 않은 것입니다.
            if(check[next] == -1){
                // 해당 개체 수를 만드는 시간은 현재 개체 수를 만드는 시간 + 1초
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}

// 체크 배열 초기화를 위한 함수
void init(){
    for(int i=1; i<max_int; i++){
        check[i] = -1;
    }
}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        // 1. 체크 배열을 -1로 초기화합니다.
        init();

        // 2. 목표 개체 수를 입력받는다.
        scanf("%d", &n);

        // 3. 현재 한 마리가 있고, 필요한 최소 시간은 0초입니다.
        // 따라서, 1을 0으로 체크합니다.
        check[1] = 0;
        bfs(1);

        // 4. 결과를 출력합니다.
        printf("%d\n", check[n]);
    }
}

