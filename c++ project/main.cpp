#include <iostream>
#include <queue>

#define max_int 51
using namespace std;

int n, m, start_i, start_j, end_i, end_j;
char a[max_int][max_int];
int water_day[max_int][max_int];
int check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> water;

void water_bfs() {
    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(water_day[nx][ny] == 0 && a[nx][ny] == '.'){
                    water_day[nx][ny] = water_day[x][y] + 1;
                    water.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(start_i, start_j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(check[nx][ny] == 0 && (a[nx][ny] == '.' || a[nx][ny] == 'D')){
                    if(water_day[nx][ny] == 0){
                        check[nx][ny] = check[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }else{
                        if(water_day[nx][ny] > check[x][y] + 1){
                            check[nx][ny] = check[x][y] + 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%s", a[i]);
        for(int j=0; j<m; j++){
            if(a[i][j] == 'S'){
                start_i = i;
                start_j = j;
            }
            else if(a[i][j] == 'D'){
                end_i = i;
                end_j = j;
            }
            else if(a[i][j] == '*'){
                water.push(make_pair(i, j));
            }
        }
    }

    water_bfs();

    bfs();

    if(check[end_i][end_j] != 0){
        printf("%d\n", check[end_i][end_j]);
    }
    else{
        printf("KAKTUS\n");
    }
}