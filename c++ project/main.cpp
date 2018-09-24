#include <iostream>
#define max_int 2001

using namespace std;

//시간 복잡도: O(n^2 + m)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 반복문
//사용한 자료구조: 2차원 배열

int n, m, s, e;
int a[max_int];
int d[max_int][max_int];

int main(){
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i=1; i<=n; i++){
        d[i][i] = 1;
    }
    
    for(int i=1; i<=n-1; i++){
        if(a[i] == a[i+1]){
            d[i][i+1] = 1;
        }
    }
    
    for(int j=3; j<=n; j++){
        for(int i=1; i<=j; i++){
            if(a[i] == a[j] && d[i+1][j-1] == 1){
                d[i][j] = 1;
            }
        }
    }
    
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s][e]);
    }
    
    return 0;
}
