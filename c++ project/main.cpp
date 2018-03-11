#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 3차원배열, queue, 구조체

int d[101][101][101];
bool check[101][101][101];

int dir[6][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };

int tomato_cnt = 0;
int n, m, h;

struct s{
    int height, length, width;
};

queue<s> q;

void bfs(){
    
    while(!q.empty()){
        int height = q.front().height;
        int length = q.front().length;
        int width = q.front().width;
        q.pop();
        
        for(int i=0; i<6; i++){
            
            int n_height = height+dir[i][0];
            int n_length = length+dir[i][1];
            int n_width = width+dir[i][2];
            
            if(n_height>=0 && n_height<h && n_width >= 0 && n_width < m && n_length>=0 && n_length<n){
                if(check[n_height][n_length][n_width] == false && d[n_height][n_length][n_width] == 0){

                    check[n_height][n_length][n_width] = true;
                    tomato_cnt--;
                    d[n_height][n_length][n_width] = d[height][length][width] + 1;
                    q.push({n_height, n_length, n_width});

                }
            }
        }
    }
}



int main(){

    cin >> m >> n >> h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> d[i][j][k];
                
                if(d[i][j][k] == 0){
                    tomato_cnt++;
                }
                
                if(d[i][j][k] == 1){
                    q.push({i, j, k});
                    check[i][j][k] = true;
                }
                
            }
        }
    }
    
    bfs();

    int day = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                day = max(d[i][j][k], day);
            }
        }
    }
    
    if(tomato_cnt == 0){
        cout << day-1 << endl;
    }else{
        cout << -1 << endl;
    }
    
}
