#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int m, n, k;
int cnt = 0;

void bfs(int x, int y){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(check[nx][ny] == false){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){
    cin >> m >> n >> k;
    
    for(int i=0; i<k; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        y2 = y2 - 1;
        x2 = x2 - 1;
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                check[i][j] = true;
            }
        }
        
    }
    
    vector<int> cnt_array;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false){
                bfs(i, j);
                cnt_array.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(cnt_array.begin(), cnt_array.end());
    
    cout << cnt_array.size() << endl;
    for(int i=0; i<cnt_array.size(); i++){
        cout << cnt_array[i] <<" ";
    }
    cout << endl;
}
