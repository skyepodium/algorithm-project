#include <iostream>

#define max_int 100001

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: dynamic programming
//사용한 자료구조: 1차원 배열


int n, m, s, e;
int a[max_int];
int d[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        d[i] = d[i-1] + a[i];
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", d[e] - d[s-1]);
    }
    
    
}
