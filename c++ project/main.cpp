#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define max_int 1001

using namespace std;

int t, k, m, p, a, b;
vector<int> v[max_int];
int ind[max_int];

struct info{
    int value;
    int cnt;
};

info max_stahler[max_int];
int stahaler[max_int];
int result = 0;

void init(){
    for(int i=1; i<=m; i++){
        v[i].clear();
        ind[i] = 0;
        max_stahler[i].value = 0;
        max_stahler[i].cnt = 0;
        stahaler[i] = 0;
    }
    result=0;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &k, &m, &p);
        init();
        for(int i=0; i<p; i++){
            scanf("%d %d", &a, &b);
            
            v[a].push_back(b);
            ind[b] += 1;
        }
        
        queue<int> q;
        for(int i=1; i<=m; i++){
            if(ind[i] == 0){
                stahaler[i] = 1;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i=0; i<v[node].size(); i++){
                int next = v[node][i];

                if(max_stahler[next].value == stahaler[node]){
                    max_stahler[next].cnt += 1;
                }
                
                if(stahaler[node] > max_stahler[next].value){
                    max_stahler[next].value = stahaler[node];
                    max_stahler[next].cnt = 1;
                }
                
                
                ind[next] -= 1;
                
                if(ind[next] == 0){
                    
                    if(max_stahler[next].cnt >= 2) stahaler[next] = max_stahler[next].value + 1;
                    else stahaler[next] = max_stahler[next].value;

                    result = max(result, stahaler[next]);

                    q.push(next);
                    
                }
            }
        }
        
        printf("%d %d\n", k, result);
    }
}
