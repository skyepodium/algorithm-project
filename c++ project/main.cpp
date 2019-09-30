#include <iostream>
#include <queue>
#include <vector>

#define max_int 100001
using namespace std;

int t, n, num, ind[max_int], result;
vector<int> v[max_int];

void topological_sort(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(ind[i] == 0) {      
            q.push(i);
            result++;
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            
            ind[next]--;
            if(ind[next] == 0){
                q.push(next);
                result++;
            }
        }
    }
}

void init(){
    result = n;
    for(int i=0; i<=n; i++){
        v[i].clear();
        ind[i] = 0;
    }
}

int main(){
    scanf("%d", &t);
    
    for(int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        
        init();
        
        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            v[i].push_back(num);
            ind[num]++;
        }
        
        topological_sort();
        
        printf("%d\n", result);
    }
}
