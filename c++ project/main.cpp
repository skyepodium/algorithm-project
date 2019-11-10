#include <stdio.h>

/*
 시간 복잡도:
 공간 복잡도: O(n)
 사용한 알고리즘: LowerBound(BinarySearch)
 사용한 자료구조: 1차원 배열
 */

// 나무의 최대 개수
const int kMaxCnt = 1000001;
// 나무의 최대 높이
const int kMaxHeight = 1000000000;
typedef long long lld;

int n, m, tree[kMaxCnt], result;

int max(int a, int b){
    return a > b ? a : b;
}

// 현재의 높이로 가져갈 수 있는 나무 높이의 합 계산
lld GetTree(int val){
    lld ret = 0;
    
    // 나무의 높이(tree[i])가, 설정한 높이(val) 보다 커야한다.
    for(int i=1; i<=n; i++){
        ret += tree[i] > val ? (lld)tree[i] - val : 0;
    }
    return ret;
}

/*
 바이너리 서치(LowerBound)
 내가 찾고자 하는 값(m) 이상이 처음으로 나타나는 위치(나무의 높이, 결과)를 찾는다.
 */
void LowerBound(int start, int end){
    
    int mid = 0;
    while(start < end){
        mid = (start + end) / 2;
        // 현재의 높이로 가져갈 수 있는 나무 높이의 합 계산
        lld tree_result = GetTree(mid);
        
        /*
         1) 만약 가져갈 수 있는 나무 높이의 합이, 적어도 가져가야하는 값(m) 보다 작으면
         높이를 낮게 설정 - 가져갈 수 있는 높이를 크게한다.
         */
        if(tree_result < (lld)m){
            end = mid;
        }
        /*
         2) 만약 가져갈 수 있는 나무 높이의 합이, 적어도 가져가야하는 값(m) 보다 크거나 같으면
         높이를 높게 설정 - 가져갈 수 있는 높이를 줄인다.
         
         그리고 이때의 값은 적어도 M미터 이기 때문에 결과값을 갱신해준다.
         */
        else{
            start = mid+1;
            result = max(result, mid);
        }
    }
}

int main(){
    // 1. 입력
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &tree[i]);
    
    /*
     2. 바이너리 서치(LowerBound)
     내가 찾고자 하는 값(m) 이상이 처음으로 나타나는 위치(설정하는 높이, 결과)를 찾는다.
     */
    LowerBound(0, kMaxHeight);
    
    // 3. 출력
    printf("%d\n", result);
}
