#include <iostream>
#include <queue>

using namespace std;


int n, m, r, c, l;
int d[51][51];
bool check[51][51];
int time_table[51][51];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
//왼쪽 오른쪽 아래 위

void bfs(int x, int y, int time){
    
    check[x][y] = true;
    time_table[x][y] = time;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            //0 왼쪽, 1 오른쪽, 2 아래, 3위
            int nx = x + dx[i];
            int ny = y + dy[i];

            int cur= d[x][y];
            int next = d[nx][ny];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(check[nx][ny] == false && next > 0 && time_table[x][y]+1 <= l){
                    
                    if(cur == 1){
                        if(i==0 && (next==2 || next==6 || next==7)) continue;
                        if(i==1 && (next==2 || next==4 || next==5)) continue;
                        if(i==2 && (next==3 || next==5 || next==6)) continue;
                        if(i==3 && (next==3 || next==4 || next==7)) continue;
                    }
                    
                    if(cur == 2){
                        if(i==0 || i==1) continue;
                        if(i==2 && (next==3 || next==5 || next==6)) continue;
                        if(i==3 && (next==3 || next==4 || next==7)) continue;
                    }
                   
                    if(cur == 3){
                        if(i==2 || i==3) continue;
                        if(i==0 && (next==2 || next==6 || next==7)) continue;
                        if(i==1 && (next==2 || next==4 || next==5)) continue;
                    }
                    
                    if(cur == 4){
                        if(i==0 || i==2) continue;
                        if(i==1 && (next==2 || next==4 || next==5)) continue;
                        if(i==3 && (next==3 || next==4 || next==7)) continue;
                    }
                    
                    if(cur == 5){
                        if(i==0 || i==3) continue;
                        if(i==1 && (next==2 || next==4 || next==5)) continue;
                        if(i==2 && (next==3 || next==5 || next==6)) continue;
                    }
                    
                    if(cur == 6){
                        if(i==1 || i==3) continue;
                        if(i==0 && (next==2 || next==6 || next==7)) continue;
                        if(i==2 && (next==3 || next==5 || next==6)) continue;
                    }
                    
                    if(cur == 7){
                        if(i==1 || i==2) continue;
                        if(i==0 && (next==2 || next==6 || next==7)) continue;
                        if(i==3 && (next==3 || next==4 || next==7)) continue;
                    }
                    
                    check[nx][ny] = true;
                    time_table[nx][ny] = time_table[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    
                }
            }
        }
    }
    
}

int find_result(){
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == true && time_table[i][j] <=l){
                cnt++;
            }
            check[i][j] = false;
            time_table[i][j] = 0;
        }
    }
    
    return cnt;
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m >> r >> c >> l;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> d[i][j];
            }
        }
        bfs(r, c, 1);
        
        cout << "#" << test_case << " " <<find_result() << endl;
        
    }
    return 0;
}
