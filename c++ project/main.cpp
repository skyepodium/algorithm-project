#include <iostream>
#include <queue>
#define max_int 101
#define max_val 100001

using namespace std;

int n, m, start_point, end_point, ladder[max_int], d[max_int], ladder_node;

struct info {
    int cur;
    int cost;
};

struct cmp {
    bool operator() (const info &a, const info &b) {
        return a.cost > b.cost;
    }
};

void dijkstra(int start_node) {
    priority_queue<info, vector<info> , cmp> pq;
    d[start_node] = 0;
    pq.push({start_node, d[start_node]});
    
    while(!pq.empty()) {
        info node = pq.top();
        pq.pop();
        
        int c_node = node.cur;
        
        // 주사위
        for(int i=1; i<=6; i++) {
            int n_node = c_node + i;

            if (n_node <= 100) {
                // 도착한 칸이 사다리, 뱀이 아닐때
                ladder_node = ladder[n_node];
                if(ladder_node == -1) {
                    if(d[n_node] > d[c_node] + 1) {
                        d[n_node] = d[c_node] + 1;
                        pq.push({n_node, d[n_node]});
                    }
                }
                // 도착한 칸이 사다리, 뱀 일때
                else {
                    // 사다리 + 뱀
                    if(d[ladder_node] > d[c_node] + 1) {
                        d[ladder_node] = d[n_node] = d[c_node] + 1;
                        pq.push({ladder_node, d[ladder_node]});
                    }
                }
            }
        }
    }
}

void init () {
    for(int i=0; i<=100; i++) {
        d[i] = max_val;
        ladder[i] = -1;
    }
}

int main () {
    scanf("%d %d", &n, &m);
    
    init();
    
    for(int i=0; i<n+m; i++) {
        scanf("%d %d", &start_point, &end_point);
        
        ladder[start_point] = end_point;
    }
    
    dijkstra(1);
    
    printf("%d\n", d[100]);
}
