#include <iostream>
#include <algorithm>

#define max_int 100001
using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(n)
//사용한 알고리즘: disjoint-set
//사용한 자료구조: 1차원 배열

int t, n, m, a, b, result;

// 정점 a의 부모를 담을 배열 d
// d[a] = b라면, 정점 a의 부모는 b다.
int d[max_int];

// 정점 a를 최상위 부모로 가지고 있는 정점들의 개수
// cnt[a] = 4라면, 정점 a를 최상위 부모로 가지는 정점들의 개수는 4개이다.(자기 자신 포함)
int cnt[max_int];


// 최상위 부모를 찾는 함수
int find(int node){
    // 1) 만약, 현재 노드의 부모와 현재 노드가 같다면 최상위 노드이다.
    if(d[node] == node) return node;
    // 2) 다르다면, 재귀 호출을 통해 최상위 부모를 찾아서 넣어준다.
    else return d[node] = find(d[node]);
}

// 초기화 함수
void init() {
    for(int i=1; i<=n; i++){
        // 정점 i의 부모는 i다.
        d[i] = i;
        cnt[i] = 0;
    }
}

int main(){
    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++){
        scanf("%d %d", &n, &m);

        // 1. 초기화, 1) 부모의 정보를 담는 배열 d, 2) 개수 정보를 담을 배열 i초기화
        init();

        // 2. 두 금속을 입력받는다.
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            // 1) 각 금속의 부모를 찾는다.
            a = find(a);
            b = find(b);

            // 2) 각 금속의 최상위 부모가 다르다면
            if(a != b){
                // a 금속의 최상위 부모의 부모는 b가 된다.
                d[a] = b;
            }
        }

        // 모든 정점의 최상위 부모를 찾고, 개수를 증가시켜준다.
        for(int i=1; i<=n; i++){
            cnt[find(i)]++;
        }

        result = 0;
        // 최상위 부모로 가장 많이 선택된 정점에 대해 선택된 개수를 갱신해준다.
        for(int i=1; i<=n; i++){
            result = max(result, cnt[i]);
        }

        printf("%d\n", result);
    }
}