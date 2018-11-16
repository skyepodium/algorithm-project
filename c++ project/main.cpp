#include <iostream>

#define max_int 1000001

using namespace std;

int n, m, a, b, c;
int d[max_int];

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) d[i] = i;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            d[find(b)] = find(c);
        }
        else{
            if(find(b) == find(c)) printf("YES\n");
            else printf("NO\n");
        }
    }
}
