#include <iostream>
#include <vector>
#define max_int 101
using namespace std;

int n, m, a, b, cnt, rcnt, result, num;
bool check[max_int], rcheck[max_int];

vector<int> v[max_int];
vector<int> r[max_int];


void clear(){
    cnt = 0;
    rcnt = 0;
    for(int i=1; i<=n; i++){
        check[i] = false;
        rcheck[i] = false;
    }
}

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!check[next]){
            cnt++;
            dfs(next);
        }
    }
}

void rdfs(int node){
    rcheck[node] = true;
    
    for(int i=0; i<r[node].size(); i++){
        int next = r[node][i];
        if(!rcheck[next]){
            rcnt++;
            rdfs(next);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    num = (n+1)/2;
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        r[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        clear();
        dfs(i);
        rdfs(i);
        
        if(cnt >= num || rcnt >= num){
            result++;
        }
        
    }
    
    printf("%d\n", result);
}
