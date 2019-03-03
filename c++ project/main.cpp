#include <iostream>
#include <queue>

#define max_int 1001
using namespace std;

int t, n, m, result;
char a[max_int][max_int];
queue<pair<int, int>> fire;
queue<pair<int, int>> q;
int check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void fire_bfs(){
    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny] != '#'){
                    if(check[nx][ny] > check[x][y] + 1){
                        check[nx][ny] = check[x][y] + 1;
                        fire.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m-1){
            result = min(result, check[x][y]);
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny] != '#'){
                    if(check[nx][ny] > check[x][y] + 1){
                        check[nx][ny] = check[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);
        result = max_int*max_int;

        for(int i=0; i<n; i++){
            scanf("%s", a[i]);
            for(int j=0; j<m; j++){
                check[i][j] = max_int*max_int;
                if(a[i][j] == '*'){
                    check[i][j] = 0;
                    fire.push(make_pair(i, j));
                }else if(a[i][j] == '@'){
                    check[i][j] = 0;
                    a[i][j] = '.';
                    q.push(make_pair(i, j));
                }
            }
        }

        fire_bfs();

        bfs();

        if(result == max_int*max_int){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n", result+1);
        }
    }
}