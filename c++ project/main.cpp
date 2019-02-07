#include <iostream>
#include <algorithm>

#define max_int 101
using namespace std;

//시간 복잡도: O(mnlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 그리디, STL sort
//사용한 자료구조: 배열


int t, n, m, result;
int a[max_int];

int main(){
    scanf("%d", &t);

    for(int test_case = 1; test_case <=t; test_case++){

        // 1. 변수 초기화
        result = 0;

        // 2. 정보를 입력받는다.
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }

        // 3. m번 만큼 아이템을 사용합니다.
        while(m--){
            // 마력 내림차순으로 정렬
            sort(a, a+n, greater<int>());

            // 제일 마력이 많이 들어있는 아이템을 사용합니다.
            result += a[0];

            // 마력은 0이 되면 없어집니다.
            if(a[0] > 0) a[0]--;
        }

        // 4. 결과 출력
        printf("%d\n", result);
    }
}