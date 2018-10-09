#include <iostream>
#include <vector>
#include <queue>

#define max_int 20001
#define max_val 2147483647

using namespace std;

int n, m, start_node, a, b, c;
int dist[max_int];

struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];

//c++의 priority_queue는 max_heap이어서 min_heap으로 바꿔준다.
struct cmp{
    
    bool operator()(struct info &a, struct info &b){
        return a.cost > b.cost;
    }
};

int main(){
    scanf("%d %d %d", &n, &m, &start_node);
    
    //초기화
    for(int i=1; i<=n; i++) dist[i] = max_val;
    
    //경로 입력
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    
    priority_queue<info, vector<info>, cmp> pq;
    dist[start_node] = 0;
    pq.push({start_node, 0});
    
    while(!pq.empty()){
        
        info node = pq.top();
        pq.pop();
        
        for(int i=0; i<v[node.cur].size(); i++){
            info next = v[node.cur][i];
            
            if(dist[next.cur] > dist[node.cur] + next.cost){
                dist[next.cur] = dist[node.cur] + next.cost;
                pq.push(next);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(dist[i] == max_val) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
    
}

