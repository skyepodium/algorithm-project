#include <iostream>
#include <vector>
#include <algorithm>

#define lld long long int
#define max_int 100001
using namespace std;

int t, n, m;
lld result;
struct info{
    int start;
    int end;
    int cost;
};

bool cmp(const info &a, const info &b){
    return a.cost < b.cost;
}

int d[max_int];

void init(){
    result = 0;
    for(int i=1; i<=n; i++){
        d[i] = i;
    }
}

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d", &t);
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &n, &m);
        init();
        vector<info> v(m);
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &v[i].start, &v[i].end, &v[i].cost);
        }

        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<m; i++){
            int x = v[i].start;
            int y = v[i].end;
            x = find(x);
            y = find(y);
            if(x!=y){
                d[x] = y;
                result += v[i].cost;
            }
        }
        printf("#%d %lld\n", test_case, result);
    }
}