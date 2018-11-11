#include <iostream>
#include <algorithm>
#include <vector>

#define max_int 26
using namespace std;

int n, cnt, total = 0;

int d[max_int][max_int];
bool check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y){
    check[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    vector<int> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j] == 1 && check[i][j] == false){
                cnt = 0;
                total++;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    
    printf("%d\n", total);
    for(int i=0; i<v.size(); i++){
        printf("%d\n", v[i]);
    }
    
}
