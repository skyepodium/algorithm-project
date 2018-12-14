#include <iostream>
#include <vector>
#include <queue>

#define max_int 32001
using namespace std;

int n, m, a, b;
int ind[max_int];
vector<int> v[max_int];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        ind[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
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
