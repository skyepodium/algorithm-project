#include <iostream>
#include <algorithm>
#include <vector>

#define max_val 10000001
#define max_int 51
using namespace std;

int n, m, a, b, c;
int d[max_int][max_int];

struct info{
    int idx;
    int cost;
};

bool cmp(const info &a, const info &b){
    if(a.cost == b.cost) return a.idx < b.idx;
    else return a.cost < b.cost;
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) d[i][j] = max_val;
        }
    }
    
    while(true){
        scanf("%d %d", &a, &b);
        if(a==-1 && b==-1) break;
        
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    vector<info> v;
    
    for(int i=1; i<=n; i++){
        int score = 0;
        for(int j=1; j<=n; j++){
            score = max(score, d[i][j]);
        }
        v.push_back({i, score});
    }
    sort(v.begin(), v.end(), cmp);
    
    int max_score = v[0].cost;
    int cnt = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i].cost == max_score) cnt++;
        else break;
    }

    printf("%d %d\n", max_score, cnt);
    for(int i=0; i<cnt; i++){
        printf("%d ", v[i].idx);
    }
    printf("\n");
    
    
}
