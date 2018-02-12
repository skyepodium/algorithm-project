#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int cnt = 0;

vector<pair<int, int>> v;
vector<int> radius;
vector<int> a[3001];
bool check[3001];
int n;

void make_graph(){
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int dx = v[i].first - v[j].first;
            int dy = v[i].second - v[j].second;

            if(sqrt(dx*dx+dy*dy) <= radius[i] + radius[j]){
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
}

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){
        v.clear();
        radius.clear();
        memset(check, false, sizeof(check));
        int cnt = 0;
        for(int i=0; i<3000; i++){
            a[i].clear();
        }
        
        
        int x, y, r;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x >> y >> r;
            v.push_back(make_pair(x, y));
            radius.push_back(r);
        }
        make_graph();
        
        for(int i=0; i<n; i++){
            if(check[i] == false){
                dfs(i);
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }
}
