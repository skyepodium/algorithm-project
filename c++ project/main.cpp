#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 50001
using namespace std;

int n, m, a, b;
int parent[max_int];
int depth[max_int];
bool check[max_int];
vector<int> v[max_int];

int lca(int first, int second){
    
    if(depth[first] < depth[second]){
        swap(first, second);
    }
    
    while(depth[first] != depth[second]){
        first = parent[first];
    }
    
    while(first != second){
        first = parent[first];
        second = parent[second];
    }
    
    return first;
}


int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    check[1] = true;
    parent[1] = 0;
    depth[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == false){
                check[next] = true;
                parent[next] = node;
                depth[next] = depth[node] + 1;
                q.push(next);
            }
        }
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    
    
    
}
