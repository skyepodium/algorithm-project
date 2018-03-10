#include <iostream>
#include <queue>

using namespace std;

int d[51][51];
bool check[51][51];

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int w, h;
void dfs(int x, int y){
    check[x][y] = true;
    
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=0 && nx<w && ny>=0 && ny<h){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
}


int main(){
    
    while(1){
        cin >> w >> h;
        if(w==0 && h==0){
            break;
        }
        
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                d[i][j] = 0;
                check[i][j] = false;
            }
        }
        
        
        for(int j=0; j<h; j++){
            for(int i=0; i<w; i++){
                cin >> d[i][j];
            }
        }
        
        int cnt = 0;
        for(int j=0; j<h; j++){
            for(int i=0; i<w; i++){
                if(check[i][j] == false && d[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;
        
        
    }
    
    
    
}
