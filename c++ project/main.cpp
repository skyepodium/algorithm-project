#include <iostream>
#include <queue>
#include <vector>
#define max_int 1001
#define max_val 10000001
#define lld long long int
using namespace std;

int n, m, k, a, b;
lld c, d[max_int][200];
struct info{
    int cur;
    lld cost;
};

vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int update_cost(int node, lld val){
    int start = 1;
    int end = 100;
    int mid = 0;
    int ret = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(d[node][mid] < val){
            start = mid + 1;
        }
        else{
            ret = mid;
            end = mid - 1;
        }
    }
    
    if(ret != 0){
        for(int i=100; i>=ret; i--){
            d[node][i+1] = d[node][i];
        }
        d[node][ret] = val;
    }
    return ret;
}

void dijkstra(){
    d[1][1] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({1, d[1][1]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        
        int c_node = cur.cur;
        
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            lld n_cost = next.cost;
            
            lld new_cost = d[c_node][1] + n_cost;
            if(new_cost < d[n_node][1]){
                update_cost(n_node, new_cost);
                pq.push({n_node, d[n_node][1]});
            }else{
                if(new_cost < d[n_node][k]){
                    update_cost(n_node, new_cost);
                }
            }
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=100; j++){
            d[i][j] = max_val;
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    init();
    
    for(int i=0; i<m; i++){
        scanf("%d %d %lld", &a, &b, &c);
        v[a].push_back({b, c});
    }
    
    dijkstra();
    
    for(int i=1; i<=n; i++){
        if(d[i][k] == max_val) d[i][k] = -1;
        printf("%lld\n", d[i][k]);
    }
}
