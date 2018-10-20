#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 10001

using namespace std;

int n, m, start_node, end_node, a, b, c;
int d[max_int];
int ind[max_int];
int rind[max_int];

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];
vector<info> w[max_int];
bool check[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        ind[b] += 1;
        
        w[b].push_back({a, c});
        rind[a] += 1;
    }
    
    scanf("%d %d", &start_node, &end_node);
    
    queue<info> q;
    d[start_node] = 0;
    q.push({start_node, 0});
    
    while(!q.empty()){
        info node = q.front();
        q.pop();
        
        for(int i=0; i<v[node.cur].size(); i++){
            info next = v[node.cur][i];
            
            d[next.cur] = max(d[next.cur], d[node.cur] + next.cost);
            
            ind[next.cur] -= 1;
            
            if(ind[next.cur] == 0){
                q.push(next);
            }
        }
    }
    
    printf("%d\n", d[end_node]);
    
    int cnt = 0;
    queue<info> rq;
    check[end_node] = true;
    rq.push({end_node, d[end_node]});
    
    while(!rq.empty()){
        info node = rq.front();
        rq.pop();
        
        for(int i=0; i<w[node.cur].size(); i++){
            info next = w[node.cur][i];
            if(check[node.cur] && d[node.cur] - next.cost == d[next.cur]){
                check[next.cur] = true;
                cnt++;
            }
            rind[next.cur] -= 1;
            if(rind[next.cur] == 0) rq.push(next);
            
        }
    }

    
    printf("%d\n", cnt);
}
