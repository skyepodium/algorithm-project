#include <iostream>
#include <queue>
#include <string>

using namespace std;

//시간 복잡도: O(n^4)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

int d[51][51];
int check[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;

void bfs(int x, int y){
 
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 & nx<n && ny>=0 && ny<m){
                if(check[nx][ny] == false && d[nx][ny] == 1){
                    check[nx][ny] = true;
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    
}

void clear_check(){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j] = false;
            if(d[i][j] > 0){
                d[i][j] = 1;
            }
        }
    }
    
}

int check_max(){
    int max_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            max_cnt = max(max_cnt, d[i][j]);
        }
    }
    return max_cnt - 1;
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        for(int j=0; j<m; j++){
            if(word[j] == 'W'){
                d[i][j] = 0;
            }else{
                d[i][j] = 1;
            }
        }
    }
    
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j] == 1){
                bfs(i, j);
                result = max(check_max(), result);
                clear_check();
            }
        }
    }
    
    cout << result << endl;
    
}
