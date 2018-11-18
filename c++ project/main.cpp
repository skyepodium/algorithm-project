#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 100001

using namespace std;

int d[max_int];
int n, m, a, b, c;
struct info{
    int cur;
    int next;
    int cost;
};

vector<info> v;

bool cmp(const info &a, const info &b){
    return a.cost < b.cost;
}

int find(int node){
    if(d[node] == node) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) d[i] = i;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({a, b, c});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int result = 0;
    int max_weight = 0;
    for(int i=0; i<v.size(); i++){
        int a = find(v[i].cur);
        int b = find(v[i].next);
        
        if(a!=b){
            d[a] = b;
            result += v[i].cost;
            max_weight = max(max_weight, v[i].cost);
        }
    }
    
    printf("%d\n", result - max_weight);
    
}
