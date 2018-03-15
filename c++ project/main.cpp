#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[101];
int check[101];
int n, m;

void bfs(int start){
    check[start] = 0;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<a[node].size(); i++){
            int next = a[node][i];
            
            if(check[next] == 0){
                check[next] = check[node] + 1;
                q.push(next);
            }
            
        }
    }
}

int check_dist(int num){
    
    int total_dist = 0;
    for(int i=1; i<=n; i++){
        if(i == num){
            continue;
        }
        total_dist += check[i];
    }
    
    return total_dist;
}

void clear_check(){
    for(int i=0; i<101; i++){
        check[i] = 0;
    }
}

int main(){

    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<pair<int, int>> result;
    for(int i=1; i<=n; i++){
        bfs(i);
        result.push_back(make_pair(check_dist(i), i));
        clear_check();
    }

    sort(result.begin(), result.end());
    
    cout << result[0].second << endl;
}
