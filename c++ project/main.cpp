#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

int main(){
    
    int n, m, start;
    cin>>n>>m>>start;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(v);
    }
    for(int i=1; i<=n; i++){
        sort(a[i].begin(), a[i].end());
    }
}
