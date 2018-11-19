#include <iostream>
#include <queue>

#define max_int 126
#define max_val 2147483647
using namespace std;

int n, idx = 1;
int d[max_int][max_int];
int a[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x;
    int y;
    int cost;
};

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int main(){
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
                d[i][j] = max_val;
            }
        }
        
        d[0][0] = a[0][0];
        priority_queue<info, vector<info>, cmp> pq;
        pq.push({0, 0, d[0][0]});
        while(!pq.empty()){
            info node = pq.top();
            pq.pop();
            
            int x = node.x;
            int y = node.y;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(d[nx][ny] > d[x][y] + a[nx][ny]){
                        d[nx][ny] = d[x][y] + a[nx][ny];
                        pq.push({nx, ny, d[nx][ny]});
                    }
                }
            }
        }
        
        printf("Problem %d: %d\n", idx, d[n-1][n-1]);
        idx++;
    }
}
