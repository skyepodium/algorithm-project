#include <iostream>
#include <queue>
#include <vector>

#define max_int 20001
#define max_val 1000001
using namespace std;

int n, m, start_node, a, b, c;
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

int main(){
    scanf("%d %d %d", &n, &m, &start_node);

    for(int i=1; i<=n; i++) d[i] = max_val;

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }

    d[start_node] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({start_node, d[start_node]});
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        int c_node = cur.cur;

        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;

            if(d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
                pq.push({n_node, d[n_node]});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(d[i] == max_val) printf("INF\n");
        else printf("%d\n", d[i]);
    }
}