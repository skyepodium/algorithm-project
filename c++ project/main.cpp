#include <iostream>
#include <vector>
#include <queue>

#define lld long long int
#define max_val 100000000001
#define max_int 100001
using namespace std;

int t, n, m, start_node, end_node, a, b, c;
lld d[max_int];
struct info{
    int cur;
    lld cost;
};
vector<info> v[max_int];

struct cmp{
    bool operator()(const info &a, const info &b){
        return a.cost > b.cost;
    }
};

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d %d %d", &n, &m, &start_node, &end_node);

        for(int i=0; i<=n; i++){
            d[i] = max_val;
            v[i].clear();
        }

        for(int i=0; i<m; i++){
            scanf("%d %d %lld", &a, &b, &c);
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }

        d[start_node] = 0;
        priority_queue<info, vector<info>, cmp> pq;
        pq.push({start_node, d[start_node]});
        while(!pq.empty()){
            info cur = pq.top();
            int c_node = cur.cur;
            pq.pop();

            for(int i=0; i<v[cur.cur].size(); i++){
                info next = v[c_node][i];
                int n_node = next.cur;
                lld n_cost = next.cost;
                if(d[n_node] > d[c_node] + n_cost){
                    d[n_node] = d[c_node] + n_cost;
                    pq.push({n_node, d[n_node]});
                }
            }
        }
        printf("#%d %lld\n", test_case, d[end_node]);
    }


}