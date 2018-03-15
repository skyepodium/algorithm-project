#include <iostream>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 2차원 배열

int d[301][301];
int melt_height[301][301];
bool check[301][301];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;

void minus_height(){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j] > 0){
            
                int m_height = 0;
                for(int k=0; k<4; k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    
                    if(nx >= 0 && nx<n && ny>=0 && ny<m){
                        if(d[nx][ny] == 0){
                            m_height++;
                        }
                    }
                    
                }
                melt_height[i][j] = m_height;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j] - melt_height[i][j] >= 0){
                d[i][j] = d[i][j] - melt_height[i][j];
            }else{
                d[i][j] = 0;
            }
        }
    }
    
}


void dfs(int x, int y){
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>= 0 && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false && d[nx][ny] > 0){
                dfs(nx, ny);
            }
        }
    }
}

void clear_check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j] = false;
        }
    }
    
}

int main(){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d[i][j];
        }
    }

    int year = 0;
    int cnt = 1;
    
    while(cnt == 1){
        minus_height();
        year++;
        cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == false && d[i][j] > 0){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        clear_check();
            
    }

    if(cnt>1){ //빙하기 두 덩어리 이상으로 분리됨
        cout << year << endl;
    }else{ //빙하가 두 덩어리 이상으로 분리되지 않음
        cout << 0 << endl;
    }
    
    
}

