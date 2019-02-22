#include <iostream>
#include <vector>
#include <queue>

#define max_int 100001

using namespace std;

int t, n, num, result;
int ind[max_int];
vector<int> v[max_int];

void init(){
    result = 0;
    for(int i=0; i<=n; i++){
        ind[i] = 0;
        v[i].clear();
    }
}

int main(){
    scanf("%d", &t);

    for(int test_case=1; test_case <= t; test_case++){
        scanf("%d", &n);

        init();

        for(int i=1; i<=n; i++){
            scanf("%d", &num);
            v[i].push_back(num);
            ind[num]++;
        }

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(ind[i] == 0){
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

                if(ind[next] == 0) {
                    q.push(next);
                    result++;
                }
            }
        }

        printf("%d\n", result);
    }
}