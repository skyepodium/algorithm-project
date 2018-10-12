#include <iostream>
#include <algorithm>
#include <vector>

#define max_int 21

using namespace std;

int n, cost;
int d[max_int];
struct info{
    int start;
    int end;
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
    scanf("%d ", &n);
    
    for(int i=1; i<=n; i++) d[i] = i;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &cost);
            v.push_back({i, j, cost});
        }
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
    
    cout << result << endl;
    
    
}
