#include <iostream>
#define max_int 201
using namespace std;

int n, m;
int parent[max_int];
int num;
int start, next_node;

int find(int node){
    if(parent[node] == node) return node;
    else return parent[node] = find(parent[node]);
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &num);
            
            if(num == 1) parent[find(i)] = find(j);
        }
    }
    
    scanf("%d", &start);
    bool is_right = true;
    for(int i=0; i<m-1; i++){
        scanf("%d", &next_node);
        if(find(start) != find(next_node)){
            is_right = false;
            break;
        }
    }
    
    if(is_right) printf("YES\n");
    else printf("NO\n");
}
