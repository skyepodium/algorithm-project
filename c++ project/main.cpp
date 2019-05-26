#include <iostream>
#include <queue>
#include <vector>
#define max_int 1001
using namespace std;

int n, m, a[max_int][max_int], check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x;
    int y;
};

vector<info> v;

void bfs(){
    
    queue<info> q;
    info start_node = v[0];
    int start_x = start_node.x;
    int start_y = start_node.y;
    check[start_x][start_y] = 0;
    q.push(start_node);
    while(!q.empty()){
        info cur = q.front();
        int x = cur.x;
        int y = cur.y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(check[nx][ny] == 0){
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1){
                v.push_back({i, j});
            }
        }
    }
    
    bfs();
    
    info end_node = v[1];
    int end_x = end_node.x;
    int end_y = end_node.y;
    
    printf("%d\n", check[end_x][end_y]);
}
