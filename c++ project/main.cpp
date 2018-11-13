#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_int 10001

using namespace std;

int n, a, b;
vector<int> v[max_int];
int ind[max_int];
int d[max_int];
int cost[max_int];
int result = 0;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &cost[i], &a);
        
        for(int j=0; j<a; j++){
            scanf("%d", &b);
            v[b].push_back(i);
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
            
            d[next] = max(d[next], d[node] + cost[next]);
            ind[next]--;
            
            if(ind[next] == 0) q.push(next);
        }
    }
    
    for(int i=1; i<=n; i++){
        result = max(result, d[i]);
    }
    
    printf("%d\n", result);
    
}
