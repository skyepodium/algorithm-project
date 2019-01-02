#include <iostream>
#include <queue>
#include <vector>

#define max_int 1001
using namespace std;

int n, m, a, b;
int ind[max_int];
vector<int> v[max_int];


int main(){
    for(int test_case=1; test_case<=20; test_case++){
        scanf("%d %d", &n, &m);

        for(int i=0; i<=n; i++){
            ind[i] = 0;
            v[i].clear();
        }

        for(int i=0; i<m; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            ind[b]++;
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(ind[i] == 0) q.push(i);
        }
        printf("#%d ", test_case);
        while(!q.empty()){
            int node = q.front();
            printf("%d ", node);
            q.pop();

            for(int i=0; i<v[node].size(); i++){
                int next = v[node][i];
                ind[next]--;
                if(ind[next] == 0){
                    q.push(next);
                }
            }
        }
        printf("\n");
    }
}