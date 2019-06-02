#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define max_int 100001
using namespace std;

int n, m, a, b, c, start_node, end_node, max_cost = 0;
int result = 1;
struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];
bool check[max_int];

void bfs(int mid){
    queue<int> q;
    check[start_node] = true;
    q.push(start_node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            info next = v[node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            if(!check[n_node] && n_cost >= mid){
                check[n_node] = true;
                q.push(n_node);
            }
        }
    }
}

bool cal_cost (int mid) {
    bfs(mid);
    
    return check[end_node];
}

void binary_search(){
    int start = 1;
    int end = max_cost;
    int mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        for(int i=1; i<=n; i++) check[i] = false;
        
        if(cal_cost(mid)){
            result = max(result, mid);
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    max_cost = 0;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        max_cost = max(max_cost, c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    scanf("%d %d", &start_node, &end_node);
    
    binary_search();
    
    printf("%d\n", result);
}
