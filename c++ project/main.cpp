#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 1001

using namespace std;

int n, m, num, start_node, end_node;
int ind[max_int];
vector<int> v[max_int];

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        scanf("%d", &num);

        for(int j=0; j<num; j++){
            scanf("%d", &end_node);
            if(j == 0){
                start_node = end_node;
            }
            else{
                v[start_node].push_back(end_node);
                start_node = end_node;
                ind[end_node] += 1;
            }
        }
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
    
    vector<int> result;
    while(!q.empty()){
        int node = q.front();
        result.push_back(node);
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            ind[next] -= 1;
            
            if(ind[next] == 0){
                q.push(next);
            }
        }
    }
    
    if(result.size() != n){
        printf("0\n");
    }
    else{
        for(int i=0; i<result.size(); i++){
            printf("%d\n", result[i]);
        }
    }
    
    
    
}
