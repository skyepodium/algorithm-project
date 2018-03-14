#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//시간 복잡도: O(n^4)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

int d[101][101];
bool check[101][101];
int color[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n = 0;
int number = 1;
vector<pair<int, int>> list;


//플러드 필로 섬 넘버링
void flood_fill(int x, int y){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        d[x][y] = number;
        color[x][y] = number;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == false && d[nx][ny] == 1){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int bfs(int x, int y){
    
    int min_cnt = 10000;
    int origin_color = color[x][y];
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
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == false && d[nx][ny] == 0){
                    d[nx][ny] = d[x][y] + 1;
                    
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
                
                //다리가 만들어진것
                if(color[nx][ny] > 0 && color[nx][ny] != origin_color){
                    min_cnt = min(min_cnt, d[x][y] - 1);
                }
            }
        }
    }
    return min_cnt;
}

void clear_check(){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(color[i][j] < 1){
                check[i][j] = false;
                d[i][j] = 0;
            }else{
                d[i][j] = 1;
            }
        }
    }
    
}


int main(){

    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
            if(d[i][j] == 1){
                list.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false && d[i][j] == 1){
                flood_fill(i, j);
                number++;
            }
        }
    }
    
    clear_check();

    int result = 10000;
    for(int i=0; i<list.size(); i++){

        result = min(result, bfs(list[i].first, list[i].second));
  
        clear_check();
    }

    cout << result << endl;
}
