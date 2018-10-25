#include <iostream>
#include <queue>

#define max_int 5000001

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 슬라이딩 윈도우
//사용한 자료구조: 덱


int n, l;
int a[max_int];
int d[max_int];
int ans[max_int];

int main(){
    scanf("%d %d", &n, &l);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    deque<pair<int, int>> q;
    for(int i=0; i<n; i++){
        int cur = a[i];
        
        if(!q.empty() && q.front().second <= i-l){
            q.pop_front();
        }
        
        while(!q.empty() && q.back().first > cur){
            q.pop_back();
        }
        
        q.push_back(make_pair(cur, i));
        ans[i] = q.front().first;
        
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
