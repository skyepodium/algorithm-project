#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(nm)
//사용한 알고리즘: dfs
//사용한 자료구조: 2차원 배열

int n;
char d[101][101];
bool check[100][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

char current;

int people1_cnt = 0;
int people2_cnt = 0;

void dfs1(int x, int y){
    
    check[x][y] = true;
    current = d[x][y];
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(check[nx][ny] == false && d[nx][ny] == current){
                dfs1(nx, ny);
            }
        }
    }
}

void dfs2(int x, int y){
    
    check[x][y] = true;
    current = d[x][y];
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(check[nx][ny] == false){
                
                if(current == 'R'){
                    
                    if(d[nx][ny] != 'B'){
                        dfs2(nx, ny);
                    }
                    
                }else if(current == 'G'){

                    if(d[nx][ny] != 'B'){
                        dfs2(nx, ny);
                    }

                }else{
                    
                    if(current == d[nx][ny]){
                        dfs2(nx, ny);
                    }
                }
            }
        }
    }
}


int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        for(int j=0; j<n; j++){
            d[i][j] = word[j];
        }
    }
    
    //아닌 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false){
                dfs1(i, j);
                people1_cnt++;
            }
        }
    }
    
    memset(check, false, sizeof(check));
    
    //맞는 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false){
                dfs2(i, j);
                people2_cnt++;
            }
        }
    }
    
    
    cout << people1_cnt << " " << people2_cnt << endl;
}
