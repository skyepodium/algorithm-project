#include <iostream>
#include <vector>
#include <queue>
#define max_int 101

using namespace std;

int n, m, a, b, cnt, rcnt, result, baseNum, d[max_int][max_int], r[max_int][max_int], pd[max_int][max_int], pr[max_int][max_int];

/*
 시간 복잡도: O(n^4)
 공간 복잡도: O(n^2)
 사용한 알고리즘: 플로이드 와샬
 사용한 자료구조: 인접 행렬
 
 설명: 플로이드 와샬을 통해 시작점에서 도달할 수 있는 모든 구슬을 구한다.
 도달 할 수 있으면 나보다 무겁거나, 가볍다는 의미
 이 때의 무겁거나 가벼운 구슬의 개수가 중간번호(n+1)/2 보다 크면 이 구슬은 중간 구슬이 될 수 없다.
 */. 

void clear(){
    cnt = 0;
    rcnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = max_int;
            r[i][j] = max_int;
            if(pd[i][j] == 1) d[i][j] = 1;
            if(pr[i][j] == 1) r[i][j] = 1;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    baseNum = (n+1)/2;
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        pd[a][b] = 1;
        pr[b][a] = 1;
    }
    
    for(int node=1; node<=n; node++){
        
        clear();
        
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                    
                    if(r[i][j] > r[i][k] + r[k][j]){
                        r[i][j] = r[i][k] + r[k][j];
                    }
                }
            }
        }
        
        for(int j=1; j<=n; j++){
            if(d[node][j] != max_int) cnt++;
            if(r[node][j] != max_int) rcnt++;
        }
        
        if(cnt >= baseNum || rcnt >= baseNum){
            result++;
        }
    }
    
    printf("%d\n", result);
}
