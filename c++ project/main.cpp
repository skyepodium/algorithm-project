#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 50001
using namespace std;

int n, m, result = 0;
int d[max_int];
struct info{
    int start;
    int end;
    int cost;
};

bool cmp(const info &a, const info &b){
    return a.cost < b.cost;
}

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) d[i] = i;

    vector<info> v(m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &v[i].start, &v[i].end, &v[i].cost);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<m; i++){
        int a = find(v[i].start);
        int b = find(v[i].end);

        if(a!=b){
            d[a] = b;
            result += v[i].cost;
        }
    }
    printf("%d\n", result);

}