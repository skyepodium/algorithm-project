#include <iostream>
#include <algorithm>
#include <vector>

#define max_int 101
#define max_val 1010000

using namespace std;

int n, m;
int d[max_int][max_int];

struct info{
    int index;
    int num;
};

bool cmp(const info &a, const info &b){
    return a.num < b.num;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) d[i][j] = max_val;
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
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
    
    vector<info> result;
    for(int i=1; i<=n; i++){
        int ret = 0;
        for(int j=1; j<=n; j++){
            if(i!=j) ret += d[i][j];
        }
        result.push_back({i, ret});
    }

    sort(result.begin(), result.end(), cmp);
    
    
    
    printf("%d\n", result[0].index);
}
