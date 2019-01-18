#include <string>
#include <vector>
#include <queue>
using namespace std;

bool check[201];

void dfs(int node, vector<vector<int>> &computers, int n){
    check[node] = true;
    for(int i=0; i<n; i++){
        int next = i;
        if(check[next] == false && computers[node][i] == 1){
            dfs(next, computers, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<=n; i++) check[i] = false;

    for(int i=0; i<n; i++){
        if(check[i] == false){
            dfs(i, computers, n);
            answer++;
        }
    }

    return answer;
}