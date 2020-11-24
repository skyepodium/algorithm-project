#include <iostream>
#include <queue>
#include <vector>
#define max_int 101
#define max_val 1501
using namespace std;

int n, m, r, item[max_int], a, b, c, d[max_int], result = 0;
struct info {
    int cur, cost;
};

vector<info> v[max_int];

int max(int a, int b) {
    return a > b ? a : b;
}

void cnt_check() {
    int ret = 0;
    for(int i=1; i<=n; i++) {
        if(d[i] <= m) {
            ret += item[i];
        }
    }
    result = max(result, ret);
}

struct cmp {
    bool operator()(const info &a, const info &b) {
        return a.cost > b.cost;
    }
};

void dijkstra(int start_node) {
    priority_queue<info, vector<info>, cmp> pq;
    d[start_node] = 0;
    pq.push({start_node, d[start_node]});
    
    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();
        
        int node = cur.cur;
        
        for(int i=0; i<v[node].size(); i++) {
            info next = v[node][i];
            
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(d[n_node] > d[node] + n_cost) {
                d[n_node] = d[node] + n_cost;
                pq.push({n_node, d[n_node]});
            }
        }
    }
}

void init () {
    for(int i=1; i<=n; i++) {
        d[i] = max_val;
    }
}

int main () {
    scanf("%d %d %d", &n, &m, &r);
    
    init() ;
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &item[i]);
    }
    
    for(int i=0; i<r; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    for(int i=1; i<=n; i++) {
        init();
        dijkstra(i);
        cnt_check();
    }
    
    printf("%d\n", result);
}
