#include <iostream>
#include <vector>

#define max_int 11
using namespace std;

int n, m, a, b;
vector<int> v[max_int];
bool check[max_int];

void init() {
    for(int i=1; i<=n; i++){
        check[i] = false;
    }
}

void dfs(int node){
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!check[next]){
            check[next] = true;
            dfs(next);
        }
    }
}

int main(){
   scanf("%d %d", &n, &m);

   for(int i=0; i<m; i++){
       scanf("%d %d", &a, &b);
       v[a].push_back(b);
       v[b].push_back(a);
   }

   bool flag = false;
   for(int i=1; i<=n; i++){
       init();
       dfs(i);
       if(check[i]){
           flag = true;
           break;
       }
   }

   if(flag) printf("YES\n");
   else printf("NO\n");

}