#include <iostream>
#define max_int 100001
using namespace std;

int n, m, a, b, d[max_int];
int p[max_int];

int find(int node){
    if(node == d[node]) return node;
    else{
        return d[node] = find(d[node]);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        d[i] = i;
    }
    
    for(int i=1; i<=n; i++){
        scanf("%d", &p[i]);
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        a = find(a);
        b = find(b);
        
        if(a != b){
            d[a] = b;
            p[a] += p[b];
            p[b] = p[a];
        }
        printf("%d\n", p[a]);
    }
    
}
