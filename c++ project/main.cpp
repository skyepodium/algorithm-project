#include <iostream>

using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(nm)
//사용한 알고리즘: 재귀 함수
//사용한 자료구조: 2차원 배열

int n, m;
int d[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt = 0;

void dfs(int x, int y, int c_dir){
    
    //청소하지 않았으면 청소
    //0은 청소안함, 1 벽, 2 청소함
    if(d[x][y] == 0){
        d[x][y] = 2;
        cnt++;
    }
    
    //왼쪽 검사 후 이동
    for(int i=0; i<4; i++){
        
        int n_dir = (c_dir + 3)%4;
        int nx = x + dx[n_dir];
        int ny = y + dy[n_dir];
        
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            
            if(d[nx][ny] == 0){
                dfs(nx, ny, n_dir);
                
                //재귀함수 종료조건을 적어야한다. DFS가 아니다
                //종료시키지 않으면 for문 더 돈다.
                return;
            }
        }
        
        //바꿔준다. 4방향 다 없으면 초기 상태에서 시계방향으로 한칸 회전한것과 같다.
        c_dir = n_dir;
    }
    
    //후진
    int nx = x - dx[c_dir];
    int ny = y - dy[c_dir];
    
    //뒤가 벽이 아니면 후진
    if(d[nx][ny] != 1){
        dfs(nx, ny, c_dir);
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
    
    dfs(start_x, start_y, c_dir);
    
    cout << cnt << endl;
    
}
