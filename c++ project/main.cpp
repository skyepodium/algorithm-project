#include <iostream>
#include <vector>
#include <queue>

#define max_int 32001
using namespace std;

int n, m;
vector<int> v[max_int];
int ind[max_int];

struct cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        ind[b]++;
    }
    
    priority_queue<int, vector<int>, cmp> pq;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0) pq.push(i);
    }
    
    while(!pq.empty()){
        int node = pq.top();
        printf("%d ", node);
        pq.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            ind[next]--;
            if(ind[next] == 0) pq.push(next);
        }
    }
    printf("\n");
    
}
