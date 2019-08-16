#include <iostream>
#include <queue>
#define max_int 301
#define max_val 2147483647
using namespace std;

int n, m, a[max_int][max_int], d[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x, y, cost;
};

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};


void dijkstra(){
    priority_queue<info, vector<info>, cmp> pq;
    d[1][1] = 0;
    pq.push({1, 1, d[1][1]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        
        int x = cur.x;
        int y = cur.y;
        int cost = cur.cost;
        
        for(int i=0; i<2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || nx > n || ny < 1 || ny> m) continue;
            
            if(d[nx][ny] > d[x][y] + cost){
                d[nx][ny] = d[x][y] + cost;
                pq.push({nx, ny, d[nx][ny]});
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            d[i][j] = max_val;
        }
    }
    
    dijkstra();
    
    printf("%d\n", d[n][m]);
}
