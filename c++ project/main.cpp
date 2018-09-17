#include <iostream>
#include <queue>
#define max_int 10001

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int check[max_int][max_int];
int d[max_int][max_int];
struct info{
    int x;
    int y;
};
info arr[max_int];
int n, m;

void bfs(int x, int y){
    
    check[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == 0){
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bfs(i, j);
        }
    }
}
