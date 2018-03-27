#include <iostream>
#include <algorithm>

using namespace std;

//시간 복잡도: O(nm)
//공간 복잡도: O(nm)
//사용한 알고리즘: 동적 계획법 Bottom Up
//사용한 자료구조: 2차원 배열


int d[1001][1001];

int main(){
    
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    int result = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(d[i][j] == 1){
                d[i][j] = min(d[i-1][j], min(d[i-1][j-1], d[i][j-1])) + 1;
                result = max(result, d[i][j]);
            }
        }
    }
    
    cout << result * result << endl;
    
}

