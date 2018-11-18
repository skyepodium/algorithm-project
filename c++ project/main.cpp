#include <iostream>
#include <vector>
#include <queue>

#define max_int 1001
using namespace std;

int t, n, m, a, b;
int d[max_int];
bool check[max_int];

struct info{
    int cur;
    int next;
};

int main(){
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++){
            d[i] = i;
            check[i] = false;
        }
        
        vector<int> v[max_int];
        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        check[1] = true;
        queue<int> q;
        for(int i=0; i<v[1].size(); i++){
            q.push(v[1][i]);
        }
        
        int result = 0;
        for(int i=0; i<n-1; i++){
            int next;
            while(!q.empty()){
                next = q.front();
                q.pop();
                
                if(check[next] == false){
                    check[next] = true;
                    result++;
                    break;
                }
            }
            
            for(int i=0; i<v[next].size(); i++){
                q.push(v[next][i]);
            }
        }
        printf("%d\n", result);
        
    }
}
