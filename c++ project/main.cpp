#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_int 1001

using namespace std;

int t, n, k, start_node, end_node, final_node;
int cost[max_int];
int d[max_int];
int ind[max_int];
vector<int> v[max_int];

void init(){
    for(int i=1; i<=n; i++){
        cost[i] = 0;
        d[i] = 0;
        ind[i] = 0;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d", &n, &k);
        
        init();

        
        for(int i=1; i<=n; i++){
            scanf("%d", &cost[i]);
        }
        
        for(int i=1; i<=k; i++){
            scanf("%d %d", &start_node, &end_node);
            v[start_node].push_back(end_node);
            ind[end_node] += 1;
        }
        
        scanf("%d", &final_node);
        
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(ind[i] == 0){
                q.push(i);
                d[i] = cost[i];
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i=0; i<v[node].size(); i++){
                int next = v[node][i];
                
                d[next] = max(d[next], d[node] + cost[next]);
                
                ind[next] -= 1;
                
                if(ind[next] == 0){
                    q.push(next);
                }
            }
        }
        
        printf("%d\n", d[final_node]);
        
    }
    
}
