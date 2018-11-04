#include <iostream>
#include <queue>
#include <vector>

#define max_val 2147483647
#define max_int 126
using namespace std;

int n, idx;
int a[max_int][max_int];
int d[max_int][max_int];
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

    idx = 0;
    while(true){
        scanf("%d", &n);
        idx++;
        if(n==0) break;
        
        //1. 지도를 입력받는다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
                d[i][j] = max_val;
            }
        }
        
        priority_queue<info, vector<info>, cmp> pq;
        d[0][0] = a[0][0];
        pq.push({0, 0, d[0][0]});
        
        while(!pq.empty()){
            
            int x = pq.top().x;
            int y = pq.top().y;
            int cost = pq.top().cost;
            pq.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(d[nx][ny] > cost + a[nx][ny]){
                        d[nx][ny] = cost + a[nx][ny];
                        pq.push({nx, ny, d[nx][ny]});
                    }
                }
            }
        }
        
        printf("Problem %d: %d\n", idx, d[n-1][n-1]);
        
    }
}
