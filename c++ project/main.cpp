#include <iostream>
#include <vector>

#define max_int 501
#define max_val 2147483647

using namespace std;

int t, n, m, w, a, b, c;
int dist[max_int];

struct info{
    int cur;
    int next;
    int cost;
};

int main(){
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d", &n, &m, &w);
        for(int i=1; i<=n; i++) dist[i] = max_val;
        vector<info> v;
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &a, &b, &c);
            v.push_back({a, b, c});
            v.push_back({b, a, c});
            
        }
        for(int i=0; i<w; i++){
            scanf("%d %d %d", &a, &b, &c);
            v.push_back({a, b, -c});
        }
        
        dist[1] = 0;
        bool negative_cycle = false;
        for(int i=1; i<=n; i++){
            for(int j=0; j<v.size(); j++){
                int cur = v[j].cur;
                int next = v[j].next;
                int cost = v[j].cost;
                
                if(dist[cur] != max_val && dist[next] > dist[cur] + cost){
                    dist[next] = dist[cur] + cost;
                    if(i == n){
                        negative_cycle = true;
                    }
                }
            }
        }
        
        if(negative_cycle) printf("YES\n");
        else printf("NO\n");

    }
    
    
}
