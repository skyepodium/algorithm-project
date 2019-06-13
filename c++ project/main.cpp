#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_int 10001
#define max_val 10000000001
#define lld long long int
using namespace std;

int n, m, k, a, b, c;
lld result = max_val;
struct info{
    int cur;
    lld cost;
    int cnt;
};
vector<info> v[max_int];
lld d[max_int][21];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

void init(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            d[i][j] = max_val;
        }
    } 
}

void dijkstra() {
    priority_queue<info, vector<info>, cmp> pq;
    d[1][k] = 0;
    pq.push({1, d[1][k], k});
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;
        int c_cnt = cur.cnt;
        for(int i=0; i < v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            lld n_cost = next.cost;
            
            if(d[n_node][c_cnt] > d[c_node][c_cnt] + n_cost){
                d[n_node][c_cnt] = d[c_node][c_cnt] + n_cost;
                pq.push({n_node, d[n_node][c_cnt], c_cnt});
            }

            if(c_cnt > 0){
                if(d[n_node][c_cnt-1] > d[c_node][c_cnt]){
                    d[n_node][c_cnt-1] = d[c_node][c_cnt];
                    pq.push({n_node, d[n_node][c_cnt-1], c_cnt-1});
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    init();
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c, 0});
        v[b].push_back({a, c, 0});
    }
    
    dijkstra();
    
    for(int j=0; j<=k; j++){
        result = min(result, d[n][j]);
    }
    
    printf("%lld\n", result);
}
