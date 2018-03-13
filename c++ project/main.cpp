#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS, 플러드 필
//사용한 자료구조: 2차원 배열

int d[101][101];
bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n;
int rain=1;

void dfs(int x, int y){
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(check[nx][ny] == false && d[nx][ny] > rain){
                dfs(nx, ny);
            }
        }
    }
    
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }
    
    
    int result = 1;

    while(rain<101){

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == false && d[i][j] > rain){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        result = max(result, cnt);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check[i][j] = false;
            }
        }
        rain++;

    }
    
    cout << result << endl;

    
}

