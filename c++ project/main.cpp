#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

//시간 복잡도: O(n^5)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 3중 for문, BFS
//사용한 자료구조: 2차원 배열


int n,m;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int d[8][8];
bool check[8][8];
int result = 0;

int main(){
    
    cin >> n >> m;

    vector<pair<int, int>> virus;
    vector<pair<int, int>> wall;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d[i][j];
            
            // 바이러스 벡터
            if(d[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }
            
            // 빈공간 벡터
            if(d[i][j] == 0){
                wall.push_back(make_pair(i, j));
            }

        }
    }
    
    for(int i=0; i<wall.size(); i++){
        for(int j=i+1; j<wall.size(); j++){
            for(int k=j+1; k<wall.size(); k++){
                
                //3중 for문으로 벽세우기
                d[wall[i].first][wall[i].second] = 1;
                d[wall[j].first][wall[j].second] = 1;
                d[wall[k].first][wall[k].second] = 1;

                // BFS를 상용해서 바이러스 전파하기 위해 q벡터 생성
                queue<pair<int, int>> q;
                for(int i=0; i<virus.size(); i++){
                    q.push(make_pair(virus[i].first, virus[i].second));
                }
                
                //바이러스 전파 with BFS
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    check[x][y] = true;
                    q.pop();
                    
                    for(int i=0; i<4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        
                        if(nx>=0 && nx<n && ny>=0 && ny< m){
                            if(check[nx][ny] == false && d[nx][ny] == 0){
                                check[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
                
                // 안정영역의 갯수 검사
                int cnt = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(d[i][j] == 0 && check[i][j] == false){
                            cnt++;
                        }
                    }
                }
                
                // 최대값 갱신
                result = max(result, cnt);
                
                // 체크 배열 초기화
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        check[i][j] = false;
                    }
                }
                
                // 벽정보 초기화
                d[wall[i].first][wall[i].second] = 0;
                d[wall[j].first][wall[j].second] = 0;
                d[wall[k].first][wall[k].second] = 0;

            }
        }
    }
    
    cout << result << endl;
    
    
    
}

