#include<iostream>
#include<stack>

using namespace std;

int d[51][51];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cnt = 0;

struct position{
    int x;
    int y;
    int dir;
};

void dfs(int x, int y, int dir){

    stack<position> s;
    s.push( { x, y, dir });
    
    while(!s.empty()){
        x = s.top().x;
        y = s.top().y;
        dir = s.top().dir;
        
        if(d[x][y] == 0){
            d[x][y] = 2;
            cnt++;
        }
        s.pop();
        
        for(int i=0; i<4; i++){
            int n_dir = (dir+3)%4;
            int nx = x + dx[n_dir];
            int ny = y + dy[n_dir];
            dir = n_dir;

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(d[nx][ny] == 0){
                    s.push( {nx, ny, n_dir });
                }
            }
        }

        
        int n_dir = (dir+2)%4;
        int nx = x + dx[n_dir];
        int ny = y + dy[n_dir];
        if(d[nx][ny] != 1){
            s.push( {nx, ny, dir });
        }
        
    }

    
    
    
}

int main(){
    
    cin >> n >> m;
    
    int c_x, c_y, c_dir;
    cin >> c_x >> c_y >> c_dir;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d[i][j];
        }
    }
    
    dfs(c_x, c_y, c_dir);
    
    cout << cnt << endl;
    
}
