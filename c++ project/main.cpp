#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

int n, m;
int map[51][51];
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, 1, 0, -1};

int c_x;
int c_y;
int c_dir;

int cnt = 0;

void solve(int cx, int cy, int cdir);

int main(){
    cin>>n>>m;
    cin>>c_x>>c_y>>c_dir;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }

    solve(c_x, c_y, c_dir);
    cout<<cnt<<endl;
}

void solve(int cx, int cy, int cd){
    
    if(map[cx][cy] == 0){
        map[cx][cy] = 2;
//        cout<<" c "<<cx<<" " <<cy<<" "<<cd<<endl;
        cnt++;
    }
    
    for(int i=0; i<4; i++){
        int nd = (cd + 3) % 4;
        int nx = cx + dx[nd];
        int ny = cy + dy[nd];
        if(map[nx][ny] == 0){
            solve(nx, ny, nd);
            return;
        }else{
//            cout<<" turn "<<nd<<" "<<i<<endl;
            cd = nd;
        }
    }
    
    if(map[cx - dx[cd]][cy - dy[cd]] != 1){
        cx = cx - dx[cd];
        cy = cy - dy[cd];
//        cout<<" back "<<cd<<endl;
        solve(cx, cy, cd);
    }
    
}

