#include <iostream>

using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(nm)
//사용한 알고리즘: 반복문
//사용한 자료구조: 2차원 배열

int n, m;
int d[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt = 0;

void robot_move(int x, int y, int c_dir){
    
    while(true){
        
        if(d[x][y] == 0){
            d[x][y] = 2;
            cnt++;
        }
        
        //네 방향에 청소할 구역이 없을때
        if(d[x+1][y] != 0 && d[x-1][y] != 0 && d[x][y+1] != 0 && d[x][y-1] != 0){
            
            // 벽이 아니면
            if(d[x-dx[c_dir]][y-dy[c_dir]] != 1){
                x = x - dx[c_dir];
                y = y - dy[c_dir];
                
            // 벽이면
            }else{
                break;
            }
            
        }else{
            //왼쪽 방향에 청소할 부분이 없으면 방향 바꾸고 이동
            
            c_dir = (c_dir + 3)%4;
            if(d[x+dx[c_dir]][y+dy[c_dir]] == 0){
                x = x + dx[c_dir];
                y = y + dy[c_dir];
            }
        }
        
        
        
    }
    
    
}

int main(){
    
    cin >> n >> m;
    
    int start_x, start_y, c_dir;
    cin >> start_x >> start_y >> c_dir;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d[i][j];
        }
    }
    
    robot_move(start_x, start_y, c_dir);
    
    cout << cnt << endl;
    
}
