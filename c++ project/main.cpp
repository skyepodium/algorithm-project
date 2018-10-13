#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 10001

using namespace std;

int n, m, a, b, c;
struct info{
    int start;
    int end;
    int cost;
};
int d[max_int];

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
    
    vector<info> v;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({a, b, c});
    }
    
    sort(v.begin(), v.end(), cmp);
 
    int result = 0;
    for(int i=0; i<(int)v.size(); i++){
        int start = v[i].start;
        int end = v[i].end;
        int cost = v[i].cost;
        
        if(find(start) != find(end)){
            d[find(start)] = find(end);
            result = result + cost;
        }
    }
    
    printf("%d\n", result);
}
