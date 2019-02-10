#include <iostream>
#include <queue>

#define max_int 101
using namespace std;

int n, m, start_x, start_y, end_x, end_y;
char a[max_int][max_int];
int check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(check[nx][ny] == 0 && a[nx][ny] != '#'){
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
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
                start_x = i;
                start_y = j;
            }
            else if(a[i][j] == 'E'){
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    printf("%d\n", check[end_x][end_y] - 1);
}