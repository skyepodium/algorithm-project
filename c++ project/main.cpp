#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 2차원 배열

int d[101][101];
bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int result = 0;

void dfs(int x, int y){
    check[x][y] = true;
    result++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx>=0 && nx<101 && ny>=0 && ny<101){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
    
}

int main(){
    
    for(int i=0; i<4; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        y2 = y2 - 1;
        x2 = x2 - 1;
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                d[i][j] = 1;
            }
        }
        
    }
    
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(check[i][j] == false && d[i][j] == 1){
                dfs(i, j);
            }
        }
    }
    
    cout << result << endl;
    
}
