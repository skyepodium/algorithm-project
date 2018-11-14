#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_int 501
using namespace std;

int n, num;
int cost[max_int];
int d[max_int];
int ind[max_int];
vector<int> v[max_int];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &cost[i]);
        
        while(true){
            scanf("%d", &num);
            if(num == -1) break;
            
            v[num].push_back(i);
            ind[i]++;
        }
    }
    
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
            
            d[next] = max(d[next], cost[next] + d[node]);
            
            ind[next]--;
            if(ind[next] == 0) q.push(next);
        }
    }
    
    for(int i=1; i<=n; i++){
        printf("%d\n", d[i]);
    }
    
    
}
