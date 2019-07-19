#include <iostream>
#define max_int 1025
using namespace std;

int n, m, a[max_int][max_int], d[max_int][max_int], tree[max_int][max_int], cmd, x, y, value;
int start_x, start_y, end_x, end_y;

void update(int x, int y, int delta){
    int ty;
    while(x <= n){
        ty = y;
        while(ty <= n){
            tree[x][ty] += delta;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

int get_data(int x, int y){
    int ret = 0;
    int ty;
    while(x >= 1){
        ty = y;
        while(ty >= 1){
            ret += tree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            update(i, j, a[i][j]);
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d", &cmd);
        
        if(cmd == 0){
            scanf("%d %d %d", &x, &y, &value);
            int delta = value - a[x][y];
            a[x][y] = value;
            update(x, y, delta);
        }
        else{
            scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
            
            int result = get_data(end_x, end_y) - get_data(start_x - 1, end_y) - get_data(end_x, start_y - 1) + get_data(start_x - 1, start_y - 1);
            printf("%d\n", result);
        }
    }
}
