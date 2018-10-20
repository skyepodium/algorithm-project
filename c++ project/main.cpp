#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 10001

using namespace std;

int n, cnt, num;
int cost[max_int];
int d[max_int];
int ind[max_int];
vector<int> v[max_int];

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &cost[i]);
        
        scanf("%d", &cnt);
        
        for(int j=0; j<cnt; j++){
            scanf("%d", &num);
            v[num].push_back(i);
            ind[i] += 1;
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
            ind[next] -= 1;
            
            if(ind[next] == 0){
                q.push(next);
            }
        }
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        result = max(result, d[i]);
    }
    
    printf("%d\n", result);
    
}
