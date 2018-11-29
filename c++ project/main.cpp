#include <iostream>
#include <queue>

#define lld long long int
#define max_val 2147483641
#define max_int 101
using namespace std;

int n, m, start_node, end_node, a, b, c;
lld d[max_int];
bool check[max_int];

struct info{
    int cur;
    int next;
    lld cost;
};

info edge[max_int];
lld plus_money[max_int];

int main(){
    scanf("%d %d %d %d", &n, &start_node, &end_node, &m);
    
    for(int i=0; i<n; i++){
        d[i] = -max_val;
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %lld", &edge[i].cur, &edge[i].next, &edge[i].cost);
        edge[i].cost *= -1;
    }
    
    for(int i=0; i<n; i++){
        scanf("%lld", &plus_money[i]);
    }
    
    for(int i=0; i<m; i++){
        edge[i].cost = edge[i].cost + plus_money[edge[i].next];
    }
    
    d[start_node] = plus_money[start_node];
    
    bool negative_cycle = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cur = edge[j].cur;
            int next = edge[j].next;
            lld cost = edge[j].cost;
            
            if(d[next] <= d[cur] + cost){
                d[next] = d[cur] + cost;
                if(i==n-1) negative_cycle = true;
                check[next] = true;
            }
        }
    }
    
    if(check[end_node] == false){
        printf("gg\n");
    }
    else{
        if(negative_cycle){
            printf("Gee\n");
        }
        else{
            printf("%lld\n", d[end_node]);
        }
    }

    
}
