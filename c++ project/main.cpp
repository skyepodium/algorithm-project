#include <iostream>
#include <queue>
#include <vector>

#define max_int 32001

using namespace std;

int n, m, start_node, end_node;
int ind[max_int];
vector<int> v[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &start_node, &end_node);
        v[start_node].push_back(end_node);
        ind[end_node]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        
        int node = q.front();
        printf("%d ", node);
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            ind[next]--;
            if(ind[next] == 0){
                q.push(next);
            }
        }
    }
    
    printf("\n");
}
