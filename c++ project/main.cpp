#include <iostream>
#include <queue>
#include <vector>

#define max_int 101
#define max_val 2147483647

using namespace std;

struct info{
    int x;
    int y;
    int cost;
};

vector<info> v[max_int];
int n, m;
int a[max_int][max_int];
int d[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};


int main(){
    scanf("%d %d", &m, &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
            d[i][j] = max_val;
        }
    }
    
    priority_queue<info, vector<info>, cmp> pq;
    d[0][0] = 0;
    pq.push({0, 0, d[0][0]});
    
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        int x = node.x;
        int y = node.y;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                
                int n_cost = 0;
                if(a[nx][ny] == 1) n_cost = 1;
                
                if(d[nx][ny] > d[x][y] + n_cost){
                    d[nx][ny] = d[x][y] + n_cost;
                    pq.push({nx, ny, d[nx][ny]});
                }
            }
        }
    }
    
    printf("%d\n", d[n-1][m-1]);
    
    
    
    
    
    
    
}
