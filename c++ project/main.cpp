#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define max_int 20001
using namespace std;

int check[max_int];
int max_distance = 0;
vector<int> v[max_int];

void bfs(int node){
    check[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            cout << "asdf" << endl;
            int next = v[node][i];
            if(check[next] == -1){
                check[next] = check[node] + 1;
                max_distance = max(max_distance, check[next]);
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0; i<n; i++){
        check[i] = false;
        cout << edge[i][0] << " " << edge[i][1] << endl;
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }


    check[1] = 0;
    bfs(1);
    for(int i=1; i<=n; i++){
        cout << check[i] << endl;
    }
    for(int i=1; i<=n; i++){
        if(check[i] == max_distance) answer++;
    }
    return answer;
}