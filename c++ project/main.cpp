#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 2차원 배열

int w, h;
int a[50][50];
bool check[50][50];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int x, int y){
    check[x][y] = true;
    
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<w && 0<=ny && ny<h){
            if(a[nx][ny] == 1 && check[nx][ny] == false){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    
    while(cin >> w >> h){
        if(w == 0 && h == 0){
            break;
        }
        
        for(int j=0; j<h; j++){
            for(int i=0; i<w; i++){
                cin >> a[i][j];
            }
        }
        
        memset(check, false, sizeof(check));
        
        int cnt = 0;
        for(int j=0; j<h; j++){
            for(int i=0; i<w; i++){
                if(a[i][j] == 1 && check[i][j] == false){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;
    }
}
