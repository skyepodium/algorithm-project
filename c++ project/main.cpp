#include <iostream>
#include <queue>
#include <vector>

#define max_val 2147483647
#define max_int 20001
using namespace std;

int n, m, start_node, a, b, c;
int d[max_int];
struct info{
    int cur;
    int cost;
};

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

vector<info> v[max_int];

int main(){
    scanf("%d %d %d", &n, &m, &start_node);
    
    for(int i=1; i<=n; i++) d[i] = max_val;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    
    priority_queue<info, vector<info>, cmp> pq;
    d[start_node] = 0;
    pq.push({start_node, d[start_node]});
    
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        
        for(int i=0; i<v[node.cur].size(); i++){
            info next = v[node.cur][i];
            
            if(d[next.cur] > d[node.cur] + next.cost){
                d[next.cur] = d[node.cur] + next.cost;
                pq.push({next.cur, d[next.cur]});
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(d[i] != max_val) printf("%d\n", d[i]);
        else printf("INF\n");
    }
    
}
