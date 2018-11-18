#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

#define max_int 801
#define max_val 2147483647

using namespace std;

int n, m, a, b, c, start_node, end_node;
int d[max_int];

struct info{
    int cur;
    int cost;
};

vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

void dijkstra(int start){

    priority_queue<info, vector<info>, cmp> pq;
    d[start] = 0;
    pq.push({start, d[start]});
    while(!pq.empty()){
        info node = pq.top();
        pq.pop();
        
        for(int i=0; i<v[node.cur].size(); i++){
            info next = v[node.cur][i];
            
            if(d[next.cur] > d[node.cur] + next.cost){
                d[next.cur] = d[node.cur] + next.cost;
                pq.push({next.cur, d[next.cur]});
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) d[i] = max_val;
 
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    scanf("%d %d", &start_node, &end_node);
    
    vector<pair<int, int>> a;
    a.push_back(make_pair(1, start_node));
    a.push_back(make_pair(start_node, end_node));
    a.push_back(make_pair(end_node, n));
    
    int first_result = 0;
    bool first_possible = true;
    for(int i=0; i<a.size(); i++){
        for(int i=1; i<=n; i++) d[i] = max_val;

        int start = a[i].first;
        int end = a[i].second;
        dijkstra(start);
        if(d[end] == max_val){
            first_possible = false;
            break;
        }
        first_result += d[end];
    }

    vector<pair<int, int>> b;
    b.push_back(make_pair(1, end_node));
    b.push_back(make_pair(end_node, start_node));
    b.push_back(make_pair(start_node, n));
    
    int second_result = 0;
    bool second_possible = true;
    for(int i=0; i<a.size(); i++){
        for(int i=1; i<=n; i++) d[i] = max_val;
        
        int start = b[i].first;
        int end = b[i].second;
        dijkstra(start);
        if(d[end] == max_val){
            second_possible = false;
            break;
        }
        second_result += d[end];
    }

    
    if(first_possible && second_possible) printf("%d\n", min(first_result, second_result));
    else printf("-1\n");

}
