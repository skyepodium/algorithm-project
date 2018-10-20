#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 101
using namespace std;

int n, m, x, y, z;
int ind[max_int];
int cnt[max_int][max_int];
int d[max_int][max_int];

vector<int> v[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &z);
        v[y].push_back(x);
        cnt[x][y] = z;
        ind[x]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
            d[i][i] = 1;
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            for(int j=1; j<=n; j++){
                if(d[node][j] != 0){
                    d[next][j] += cnt[next][node] * d[node][j];
                }
            }
            
            ind[next]--;
            
            if(ind[next] == 0){
                q.push(next);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(d[n][i] != 0){
            printf("%d %d\n", i, d[n][i]);
        }
    }
    
    
}
