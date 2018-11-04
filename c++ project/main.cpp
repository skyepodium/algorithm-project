#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_val 2147483647
#define max_int 10001
using namespace std;

int t, n, m, start_node, a, b, c, cnt, max_time;
int d[max_int];

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

void init(){
    for(int i=0; i<=n; i++){
        d[i] = max_val;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &n, &m, &start_node);
        init();
        
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            v[b].push_back({a, c});
        }
        
        d[start_node] = 0;
        priority_queue<info, vector<info>, cmp> pq;
        pq.push({start_node, 0});
        
        while(!pq.empty()){
            info node = pq.top();
            pq.pop();
            
            for(int i=0; i<v[node.cur].size(); i++){
                info next = v[node.cur][i];
                
                if(d[next.cur] > d[node.cur] + next.cost){
                    d[next.cur] = d[node.cur] + next.cost;
                    pq.push(next);
                }
            }
        }
        
        cnt = 0;
        max_time = 0;
        for(int i=1; i<=n; i++){
            if(d[i] != max_val){
                cnt++;
                max_time = max(max_time, d[i]);
            }
        }
        
        
        printf("%d %d\n", cnt, max_time);
    }
    
}
