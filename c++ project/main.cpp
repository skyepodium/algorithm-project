#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: dfs
//사용한 자료구조: 1차원 배열, 2차원 벡터(링크드 리스트)


vector<int> a[100001];
bool check[100001];
bool node_list[100001];

void dfs(int node){
    check[node] = true;
    
    for(int i=0; i<a[node].size(); i++){
        
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
        
    }
}

int main(int argc, const char *argv[]) {
    int N;
    cin >> N;
    
    
    
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        
        node_list[x] = true;
        node_list[y] = true;
        
    }
    
    int group_cnt = 0;
    
    
    for(int i=0; i<=100001; i++){
        if(node_list[i] == true && check[i] == false){
            dfs(i);
            group_cnt++;
        }
    }
    
    cout << group_cnt << endl;
    
    return 0;
}


