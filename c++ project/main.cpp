#include <iostream>
#define max_int 1001
using namespace  std;

int n;
char a[max_int][max_int];

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

void cal_mine(int x, int y){
    int result = 0;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(a[nx][ny] == '.') continue;
        result += (a[nx][ny] - '0');
    }

    if(result >= 10) printf("M");
    else printf("%d", result);
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", a[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(a[i][j] != '.'){
                printf("*");
            }
            else{
                cal_mine(i, j);
            }
            if(j == n-1){
                printf("\n");
            }
        }
    }
}