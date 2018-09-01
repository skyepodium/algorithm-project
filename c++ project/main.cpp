#include <iostream>
#include <algorithm>

#define max_int 1000001
#define lld long long int

using namespace std;

//시간 복잡도: O(nlogn)
//공간 복잡도: O(n)
//사용한 알고리즘: STL sort
//사용한 자료구조: 1차원 배열


lld d[max_int];
int n = 0;
lld result = 0;
int max_cnt = 0;
int cur_cnt = 0;

int main(){
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) scanf("%lld", &d[i]);
    
    sort(d, d+n);
    
    result = d[0];
    max_cnt = 1;
    cur_cnt = 1;
    for(int i=1; i<n; i++){
        
        if(d[i] == d[i-1]) cur_cnt++;
        else cur_cnt = 1;
        
        //반복문 종료되었을때도 갱신하기 위해서, 매번 검사해준다.
        if(max_cnt < cur_cnt){
            max_cnt = cur_cnt;
            result = d[i];
        }
    }
    
    printf("%lld\n", result);
}
