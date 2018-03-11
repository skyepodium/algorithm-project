#include <iostream>
#include <cstring>

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^3)
//사용한 알고리즘: DFS
//사용한 자료구조: 2차원 배열, 인접행렬

int d[101][101];
bool check[101];
int result[101][101];
int n;

void dfs(int node){
    
    for(int i=0; i<n; i++){
        int next = i;
        if(d[node][next] == 1 && check[next] == false){
            check[next] = true;
            dfs(next);
        }
    }
}

int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dfs(i);
            if(check[j] == true){
                result[i][j] = 1;
            }
            memset(check, false, sizeof(check));
            cout << result[i][j] <<" ";
        }
        cout << endl;
    }
    
}

