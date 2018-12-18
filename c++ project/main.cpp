#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt = 1;
int result = 1;
int r, c;
bool a[26];
bool check[21][21];
char d[21][21];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
string word;

void dfs(int x, int y){
    check[x][y] = true;
    a[d[x][y] - 'A'] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(check[nx][ny] == false && a[d[nx][ny]-'A'] == false){
                cnt++;
                result = max(result, cnt);
                dfs(nx, ny);
                cnt--;
            }
        }
    }
    
    check[x][y] = false;
    a[d[x][y] - 'A'] = false;

}

int main(){
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        cin >> word;
        for(int j=0; j<c; j++){
            d[i][j] = word[j];
        }
    }
    
    dfs(0, 0);

    
    printf("%d\n", result);
}
