#include <stdio.h>

const int kMaxCnt = 17;

int n, a[kMaxCnt][kMaxCnt], d[kMaxCnt][kMaxCnt][3], result;   

int max(int a, int b){
    return a > b ? a : b;
}

int go(int x, int y, int dir){
    // 기저 사례
    if(x == 1 && y == 1 && dir == 2) return 1;

    // 메모이제이션
    if(d[x][y][dir] > 0) return d[x][y][dir];
    
    if(dir == 0){
        if(x-1 != 0 && y-1 != 0 && a[x-1][y-1] != 1) d[x][y][dir] += go(x-1, y-1, 1);
        if(x-1 != 0 && a[x-1][y] != 1) d[x][y][dir] += go(x-1, y, 0);
    }
    else if(dir == 1){
        if(x-1 != 0 && y-1 != 0 && a[x-1][y-1] != 1) d[x][y][dir] += go(x-1, y-1, 1);
        if(x-1 != 0 && a[x-1][y] != 1) d[x][y][dir] += go(x-1, y, 0);
        if(y-1 != 0 && a[x][y-1] != 1) d[x][y][dir] += go(x, y-1, 2);
    }
    else{
        if(x-1 != 0 && a[x-1][y] != 1) d[x][y][dir] += go(x-1, y, 0);
        if(y-1 != 0 && a[x][y-1] != 1) d[x][y][dir] += go(x, y-1, 2);
    }
    
    printf("%d %d %d %d\n", x, y, dir, d[x][y][dir]);

    return d[x][y][dir];
}

int main(){
    // 1. 입력
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    result = go(n-1, n-1, 1) + go(n-1, n, 0) + go(n, n-1, 2);
    printf("%d\n", result);
}
