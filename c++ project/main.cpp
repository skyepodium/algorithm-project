#include <iostream>

#define max_int 101
#define max_val 100000

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 플로이드 와샬 알고리즘
//사용한 자료구조: 인접행렬


int n, m, a, b, c;
int d[max_int][max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(c < d[a][b]) d[a][b] = c;
    }
    
    //1. 경유지
    for(int k=1; k<=n; k++){
        //2. 시작점
        for(int i=1; i<=n; i++){
            //3. 끝점
            for(int j=1; j<=n; j++){
                
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
                
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == max_val) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    
}
