#include <iostream>
#include <queue>
#include <vector>
#define max_int 1001
#define max_val 10000001
using namespace std;

int n, m, k, a, b, c, d[max_int];
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

struct cmp2{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp2> min_q[max_int];

void dijkstra(){
    d[1] = 0;
    priority_queue<info, vector<info>, cmp> pq;
    min_q[1].push(0);
    pq.push({1, d[1]});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        
        int c_node =cur.cur;
        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            
            if(d[n_node] > d[c_node] + n_cost){
                d[n_node] = d[c_node] + n_cost;
//                cout << "n_node push!! "  << n_node << " " << d[n_node] << endl;
                min_q[n_node].push(d[n_node]);
//                cout << "c_node " << c_node << " n_node " << n_node << " d_node " << d[n_node] << endl;
                pq.push({n_node, d[n_node]});
            }else{
                int temp = d[c_node] + n_cost;
                min_q[n_node].push(temp);
            }
        }
    }
}

void init(){
    for(int i=0; i<=n; i++){
        d[i] = max_val;
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    init();
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    
    dijkstra();
    
    for(int i=1; i<=n; i++){
    }
    
    for(int i=1; i<=n; i++){
        int q_size = (int)min_q[i].size();
        //cout << "q_size !!! " << q_size << endl;
        if(q_size < k){
            printf("-1\n");
            continue;
        }else{
            for(int j=1; j<=k-1; j++){
                min_q[i].pop();
            }
            printf("%d\n", min_q[i].top());
        }
    }
    
}
