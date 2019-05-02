#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max_val 2147483647
#define max_int 51
using namespace std;

int n, m, a[max_int][max_int], check[max_int][max_int], result = max_val;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x;
    int y;
};

vector<info> v, p;
queue<info> q;

void bfs(){
    while(!q.empty()){
        info cur = q.front();
        int x = cur.x;
        int y = cur.y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(a[nx][ny] == 0 && check[nx][ny] == -1){
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});
                }  //
                //
                //
            }
        }
    }

    bool isClear = true;
    int max_time = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 0){
                if(check[i][j] == -1){
                    isClear = false;
                    break;
                }else{
                    max_time = max(max_time, check[i][j]);
                }
            }
        }
    }
    
    if(isClear){
        result = min(result, max_time);
    }
}

void go(int idx){
    
    if(idx == (int)v.size()){
        
        if((int)p.size() == m){
            
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    check[i][j] = -1;
                }
            }
            
            for(int i=0; i<(int)p.size(); i++){
                int x = p[i].x;
                int y = p[i].y;
                check[x][y] = 0;
                q.push(p[i]);
            }
            bfs();
        }
        return;
    }

    p.push_back(v[idx]);
    go(idx+1);
    p.pop_back();
    
    go(idx+1);
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 2){
                v.push_back({i, j});
                a[i][j] = 0;
            }
        }
    }
    
    go(0);
 
    if(result == max_val) result = -1;
    printf("%d\n", result);
}
