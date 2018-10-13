#include <iostream>
#include <vector>

#define max_int 501
#define max_val 5010000

using namespace std;

int n, m;
int dist[max_int];
struct info{
    int cur;
    int next;
    int cost;
};


int main(){
    scanf("%d %d", &n, &m);
    
    vector<info> v(m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &v[i].cur, &v[i].next, &v[i].cost);
    }
    
    for(int i=1; i<=n; i++) dist[i] = max_val;
    dist[1] = 0;
    
    bool is_negative = false;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            
            int cur = v[j].cur;
            int next = v[j].next;
            int cost = v[j].cost;
            
            if(dist[cur] != max_val && dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
                
                if(i == n){
                    is_negative = true;
                }
            }
        }
    }
    
    if(is_negative){
        printf("-1\n");
    }
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] != max_val) printf("%d\n", dist[i]);
            else printf("-1\n");
        }
    }
    
}
