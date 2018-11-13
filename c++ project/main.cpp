#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 10001
using namespace std;

int n, m;
int d[max_int];
struct info{
    int cur;
    int next;
    int cost;
};

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

bool cmp(const info &a, const info &b){
    return a.cost < b.cost;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) d[i] = i;
    
    
    vector<info> v(m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &v[i].cur, &v[i].next, &v[i].cost);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int result = 0;
    for(int i=0; i<v.size(); i++){
        if(find(v[i].cur) != find(v[i].next)){
            d[find(v[i].cur)] = find(v[i].next);
            result += v[i].cost;
        }
    }
    
    printf("%d\n", result);
}
