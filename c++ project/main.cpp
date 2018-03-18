#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: DFS
//사용한 자료구조: 1차원 배열,2차원 벡터

vector<int> a[101];
bool check[101];

void dfs(int node){
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            check[next] = true;
            dfs(next);
        }
    }
    
}

void clear_check(){
    for(int i=0; i<101; i++){
        check[i] = false;
    }
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        int u;
        cin >> u;
        a[i].push_back(u);
    }
    
    int cnt = 0;
    vector<int> result;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            dfs(i);
        }
        if(check[i] == true){
            result.push_back(i);
            cnt++;
        }
        clear_check();
    }
 
    cout << cnt << endl;
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}
