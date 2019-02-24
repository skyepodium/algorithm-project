#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define max_int 51
using namespace std;

int n, cnt, result = 0;
char a[max_int];
vector<int> v[max_int];
int check[max_int];

void bfs(int start){

    queue<int> q;
    q.push(start);
    check[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == -1){
                check[next] = check[node] + 1;
                if(check[next] <= 2) cnt++;
                q.push(next);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", a);

        for(int j=0; j<n; j++){
            if(a[j] == 'Y'){
                v[i+1].push_back(j+1);
            }
        }
    }

    for(int i=1; i<=n; i++){

        cnt = 0;
        memset(check, -1, sizeof(check));

        bfs(i);

        result = max(result, cnt);
    }

    printf("%d\n", result);
}