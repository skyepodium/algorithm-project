#include <iostream>
#include <vector>

#define max_int 1001
using namespace std;

int t, n, m, a, b;
int d[max_int];

struct info{
    int cur;
    int next;
};

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++) d[i] = i;

        vector<info> v;
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v.push_back({a, b});
        }
        
        int result = 0;
        for(int i=0; i<v.size(); i++){
            int cur = find(v[i].cur);
            int next = find(v[i].next);
            
            if(cur != next){
                d[cur] = next;
                result++;
            }
        }
        printf("%d\n", result);
        
    }
    
    
    
    
    
}
