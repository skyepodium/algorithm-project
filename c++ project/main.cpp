#include <iostream>

#define max_int 101
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, start_x, start_y, end_x, end_y;
int d[max_int][max_int];
char temp[101];
bool check[max_int][max_int];

void dfs(int x, int y){
    check[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check[nx][ny] == false && d[nx][ny] == 0){
            dfs(nx, ny);
        }
    }
}

void init(){
    for(int i=0; i<=99; i++){
        for(int j=0; j<=99; j++){
            d[i][j] = 0;
            check[i][j] =false;
        }
    }
}

int main(){
    for(int test_case=1; test_case<=10; test_case++){
        scanf("%d", &n);
        init();
        for(int i=0; i<100; i++){
            scanf("%s", temp);
            for(int j=0; j<100; j++){
                d[i][j] = temp[j] - '0';
                if(temp[j] == '2'){
                    start_x = i;
                    start_y = j;
                }
                else if(temp[j] == '3'){
                    d[i][j] = 0;
                    end_x = i;
                    end_y = j;
                }
            }
        }

        dfs(start_x, start_y);
        printf("#%d %d\n", test_case, check[end_x][end_y]);

    }


}