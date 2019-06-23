#include <iostream>
#include <algorithm>
#define max_int 200001
using namespace std;

//시간 복잡도: O(nlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: 정렬, 이진 탐색, DP
//사용한 자료구조: 배열

int n, color_start[max_int], color_end[max_int], result[max_int], size_cnt[max_int], color_cnt[max_int];
struct info{
    int num;
    int color;
    int size;
};
info s[max_int], c[max_int];

// 크기 기준 오름차순 정렬
bool size_cmp(const info &a, const info &b){
    if(a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

// 색 기준 오름차순 정렬
bool color_cmp(const info &a, const info &b){
    if(a.color == b.color) return a.size < b.size;
    return a.color < b.color;
}

// lower_bound로 인덱스 계산
int lower_bound(int start_point, int end_point, int size, info arr[]){
    int start = start_point;
    int end = end_point;
    int mid = 0;
    
    while(start <= end){
        mid = (start + end) / 2;
        
        if(arr[mid].size < size){
            start = mid + 1;
        }
        else if(arr[mid].size == size){
            end = mid - 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return end + 1;
}

int main(){
    scanf("%d", &n);
    
    // 1. 크기 배열, 색 배열에 입력
    for(int i=1; i<=n; i++){
        scanf("%d %d", &c[i].color, &c[i].size);
        s[i].num = c[i].num = i;
        s[i].color = c[i].color;
        s[i].size = c[i].size;
    }
    
    // 2. 정렬
    // 크기 기준 오름차순 정렬
    sort(s + 1, s + 1 + n, size_cmp);
    // 색 기준 오름차순 정렬
    sort(c + 1, c + 1 + n, color_cmp);
    
    // 3. 마킹
    // 각 색에 대해 색이 시작하는 지점, 끝나는 지점 저장
    int cur_color = 0;
    for(int i=1; i<=n; i++){
        if(c[i].color != cur_color){
            color_end[cur_color] = i-1;
            cur_color = c[i].color;
            color_start[cur_color] = i;
        }
        
        if(i == n) color_end[cur_color] = i;
    }
    
    
    // 4. 누적합 계산
    // 크기 배열, 색 배열 각각 크기 누적합 계산
    int c_cur = 0, s_cur = 0;
    for(int i=1; i<=n; i++){
        c_cur += c[i].size;
        color_cnt[i] = c_cur;

        s_cur += s[i].size;
        size_cnt[i] = s_cur;
    }
    
    // 5. 계산
    for(int i=1; i<=n; i++){
        // 현재 정보
        info cur = s[i];
        int num = cur.num;
        int color = cur.color;
        int size = cur.size;

        // lower_bound로 인덱스 찾는다.
        int color_point = lower_bound(color_start[color], color_end[color], size, c);
        int size_point = lower_bound(1, n, size, s);
        
        // 포함되지 않아야할 개수 계싼
        int no_cnt = color_cnt[color_point - 1] - color_cnt[color_start[color] - 1];
        
        // 결과 저장
        result[num] = size_cnt[size_point - 1] - no_cnt;
    }
    
    // 6. 출력
    for(int i=1; i<=n; i++){
        printf("%d\n", result[i]);
    }
}
