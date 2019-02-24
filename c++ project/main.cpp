#include <iostream>
#include <vector>
#include <queue>

#define max_val 2000005;
#define max_int 201
using namespace std;

int n, m, a, b, c;
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

int p[max_int];

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }


    priority_queue<info, vector<info>, cmp> pq;

    for(int start_node=1; start_node <= n; start_node++){
        for(int i=1; i<=n; i++) d[i] = max_val;

        d[start_node] = 0;
        pq.push({start_node, 0});
        while(!pq.empty()){
            info cur = pq.top();
            int c_node = cur.cur;
            pq.pop();

            for(int i=0; i<v[c_node].size(); i++){
                info next = v[c_node][i];
                int n_node = next.cur;
                int n_cost = next.cost;
                if(d[n_node] > d[c_node] + n_cost){
                    d[n_node] = d[c_node] + n_cost;
                    p[n_node] = c_node;
                    pq.push({n_node, d[n_node]});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(i==start_node){
                printf("- ");
            }
            else if(p[i] == start_node){
                printf("%d ", i);
            }
            else{
                int cur_node = i;
                while(true){
                    if(p[cur_node] == start_node){
                        cout << cur_node << " ";
                        break;
                    }else{
                        cur_node = p[cur_node];
                    }
                }
            }
        }
        printf("\n");
    }
}