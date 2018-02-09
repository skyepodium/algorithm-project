#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열, queue

vector<int> a[10001];
int cnt = 0;
bool check[10001];

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            cnt++;
            dfs(next);
        }
    }
    
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int v, u;
        cin >> v >> u;
        a[u].push_back(v);
    }
    
    vector<pair<int, int>> result;
    for(int i=1; i<=n; i++){
        cnt = 0;
        memset(check, false, sizeof(check));
        dfs(i);
        result.push_back(make_pair(cnt, i));
    }
    
    sort(result.begin(), result.end());
    
    vector<int> final;
    final.push_back(result[result.size()-1].second);
    int max = result[result.size()-1].first;
    for(int i=result.size()-2; i>=0; i--){
        if(max != result[i].first){
            break;
        }else{
            final.push_back(result[i].second);
        }
    }
    for(int i=final.size()-1; i>=0; i--){
        cout << final[i] <<" ";
    }
    
}
