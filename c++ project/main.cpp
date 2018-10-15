#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 10001

using namespace std;

int ind[max_int];
int d[max_int];
int n, m, start_node, end_node, a, b, c;

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        ind[b] += 1;
    }
    
    scanf("%d %d", &start_node, &end_node);
    
    queue<info> q;
    d[start_node] = 0;
    q.push({start_node, d[start_node]});
    
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
    
    cout <<d[end_node] << endl;
}
