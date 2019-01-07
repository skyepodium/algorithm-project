#include <iostream>
#include <vector>
#include <queue>

#define lld long long int
#define max_int 40001
using namespace std;

int n, m, a, b, c;
struct info{
    int cur;
    int cost;
};
vector<info> v[max_int];
bool check[max_int];
int l[max_int];
int d[max_int];
int p[max_int];

void bfs(int start){
    check[start] = true;
    l[start] = 1;
    d[start] = 0;
    p[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int c_node = q.front();
        q.pop();

        for(int i=0; i<v[c_node].size(); i++){
            info next = v[c_node][i];
            int n_node = next.cur;
            int n_cost = next.cost;
            if(check[n_node] == false){
                check[n_node] = true;
                l[n_node] = l[c_node] + 1;
                d[n_node] = n_cost;
                p[n_node] = c_node;
                q.push(n_node);
            }
        }
    }
}

lld lca(int first, int second){
    if(l[first] < l[second]){
        swap(first, second);
    }

    lld result = 0;
    while(l[first] != l[second]){
        result += d[first];
        first = p[first];
    }

    while(first != second){
        result += d[first];
        result += d[second];
        first = p[first];
        second = p[second];
    }
    return result;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    bfs(1);

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%lld\n", lca(a, b));
    }
}
