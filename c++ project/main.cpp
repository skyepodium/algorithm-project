#include <iostream>
#include <vector>

#define max_int 1001
using namespace std;

int t, n, m, start_node, end_node;
int d[max_int];

struct info{
    int start_node;
    int end_node;
};

vector<info> v;

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d", &n, &m);
        
        for(int i=1; i<=n; i++) d[i] = i;
        
        for(int i=0; i<m; i++){
            scanf("%d %d", &start_node, &end_node);
            v.push_back({start_node, end_node});
        }
        
        for(int i=0; i<m; i++){
            if(find(v[i].start_node) != find(v[i].end_node)){
                d[find(v[i].start_node)] = find(v[i].end_node);
            }
        }
        
    }
    
}
