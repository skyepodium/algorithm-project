#include <iostream>
#include <queue>
#include <algorithm>

#define max_val 2147483647
#define max_int 101
using namespace std;

int n, m, a1, a2, b1, b2, c1, c2;
int d[max_int][max_int];
int a[max_int][max_int];
int b[max_int][max_int];
int check[max_int][max_int];
int result = max_val;
int cnt = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                if(check[nx][ny] == 0 && d[nx][ny] != 1){
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    vector<pair<int, int>> p(3);
    for(int i=0; i<3; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    
    for(int i=0; i<3; i++){
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                check[i][j] = 0;
            }
        }
        
        bfs(p[i].first, p[i].second);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(d[i][j] != 1 && check[i][j] != 0){
                    a[i][j] = max(a[i][j], check[i][j]);
                    b[i][j]++;
                }
                
            }
        }

    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            
            printf("%d ", a[i][j]);
            
        }
        printf("\n");
    }
    */
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            
            if(d[i][j] == 0 && b[i][j] == 3 && a[i][j] < result){
                cnt = 1;
                result = a[i][j];
            }
            else if(a[i][j] == result){
                cnt++;
            }
            
        }
    }

    if(result == max_val){
        printf("-1\n");
    }
    else{
        printf("%d\n", result-1);
        printf("%d\n", cnt);
    }

    
    
}
