#include <iostream>
#include <vector>
#include <cstring>

#define max_int 101

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 인접 리스트(2차원 벡터)


vector<int> a[max_int];
bool check[max_int];
int n = 0;
int num = 0;

void dfs(int node){
    
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        
        if(check[next] == false){
            check[next] = true;
            dfs(next);
        }
    }
}


int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;
            if(num == 1) a[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; i++){
        dfs(i);
        for(int j=0; j<n; j++){
            if(check[j] == true) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
        memset(check, false, sizeof(check));
    }
    
}
