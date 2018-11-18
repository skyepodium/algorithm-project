#include <iostream>
#include <queue>

#define max_int 1001
#define max_val 2147483647

using namespace std;

int n, m, a, b, c, start_node, end_node;

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];
int dist[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) dist[i] = max_val;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    
    scanf("%d %d", &start_node, &end_node);
    
    dist[start_node] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({start_node, dist[start_node]});
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        
        for(int i=0; i<v[node.cur].size(); i++){
            info next = v[node.cur][i];
            
            if(dist[next.cur] > dist[node.cur] + next.cost){
                dist[next.cur] = dist[node.cur] + next.cost;
                pq.push({next.cur, dist[next.cur]});
            }
        }
    }
    
    printf("%d\n", dist[end_node]);
}
