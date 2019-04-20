#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 51
#define max_val 2147483647
using namespace std;

int n, m, a[max_int][max_int], check[max_int][max_int];

struct info{
    int x;
    int y;
};

vector<info> virus;
vector<info> pick;
queue<info> q;
int result = max_val;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
void bfs() {
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(a[nx][ny] != 1 && check[nx][ny] == -1){
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    bool flag = true;
    int max_time = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 0){
                if(check[i][j] == -1){
                    flag = false;
                    break;
                }else{
                    max_time = max(max_time, check[i][j]);
                }
            }

        }
    }
    if(flag) result = min(result, max_time);
}

void go(int idx){
    if(idx == virus.size()){
        
        if(pick.size() == m){
            
            for(int i=0; i<m; i++){
                q.push({pick[i].x, pick[i].y});
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    check[i][j] = -1;
                }
            }
            
            for(int i=0; i<pick.size(); i++){
                int x = pick[i].x;
                int y = pick[i].y;
                check[x][y] = 0;
            }
            bfs();

        }
        return;
    }
    
    
    pick.push_back({virus[idx].x, virus[idx].y});
    go(idx+1);
    pick.pop_back();
    
    go(idx+1);
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 2) virus.push_back({i, j});
        }
    }
    go(0);
    
    if(result == max_val) result = -1;
    printf("%d\n", result);
    
}
