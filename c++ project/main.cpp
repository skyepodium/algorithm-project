#include <iostream>
#include <queue>
#include <vector>

#define max_val 2147483647
#define max_int 20001

using namespace std;

int n, m, a, b;
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

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<=n; i++) d[i] = max_val;
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back({b, 1});
        v[b].push_back({a, 1});
    }
    
    d[1] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({1, 0});
    
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
    
    int hide_num = 0;
    int dist = 0;
    int cnt = 0;
    
    for(int i=1; i<=n; i++){
        
        if(d[i] > dist){
            hide_num = i;
            dist = d[i];
            cnt = 1;
        }
        else if(d[i] == dist){
            cnt++;
        }
    }
    
    printf("%d %d %d\n", hide_num, dist, cnt);
    
    
    
}
