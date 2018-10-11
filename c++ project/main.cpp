#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 1001

using namespace std;

struct info{
    int start;
    int end;
    int cost;
};

int n, m, a, b, c;
int d[max_int];
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
    for(int i=0; i<v.size(); i++){
        int s = v[i].start;
        int e = v[i].end;
        
        if(find(s) != find(e)){
            d[find(s)] = find(e);
            result = result + v[i].cost;
        }
    }
    
    printf("%d\n", result);
    
}
