#include <iostream>
#include <queue>
#include <vector>
#define max_int 1501
using namespace std;

int n, m, dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0}, result;
bool check[max_int][max_int];
char a[max_int][max_int];

struct info{
    int x, y;
};

vector<info> v;

bool check_meet(){
    queue<info> q;
    info start_node = v[0];
    check[start_node.x][start_node.y] = true;
    q.push(start_node);
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            
            if(a[nx][ny] == '.' && !check[nx][ny]){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    info end_node = v[1];
    return check[end_node.x][end_node.y];
}

void clear_check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j] = false;
        }
    }
}

void melt_ice(int x, int y){
    queue<info> q;
    q.push({x, y});
    check[x][y] = true;
    
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            
            if(a[nx][ny] == '.'){
                if(!check[nx][ny]){
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            else{
                if(!check[nx][ny]){
                    check[nx][ny] = true;
                    a[nx][ny] = '.';
                }
            }
        }
    }}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        scanf("%s", a[i]);
        for(int j=0; j<m; j++){
            if(a[i][j] == 'L'){
                a[i][j] = '.';
                v.push_back({i, j});
            }
        }
    }
    
    while(true){
        clear_check();
        if(check_meet()) break;
        
        clear_check();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '.' && !check[i][j]){
                    melt_ice(i, j);
                }
            }
        }
        result++;
    }
    
    printf("%d\n", result);
}
