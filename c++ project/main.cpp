#include <iostream>
#include <algorithm>
#define max_int 1001

using namespace std;

//시간 복잡도: O(nt)
//공간 복잡도: O(nt)
//사용한 알고리즘: 동적 계획법, Bottom Up
//사용한 자료구조: 1차원, 2차원 배열


int t[max_int];
int s[max_int];
int d[max_int][10001];

int n, m;

int main(){
    
    scanf("%d %d",&n, &m);
    
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &s[i]);
    }
    
    d[1][m-t[1]] = s[1];
    for(int i=2; i<=n; i++){
        for(int j=m; j>=0; j--){
            
            if(j+t[i] <=m){
                d[i][j] = max(d[i-1][j], d[i-1][j+t[i]] + s[i]);
            }
            else{
                d[i][j] = max(d[i-1][j], d[i][j]);
            }
        }
    }
    
    int result = 0;
    for(int j=0; j<=m; j++){
        result = max(result, d[n][j]);
    }
    
    printf("%d\n", result);
    
    return 0;
}
