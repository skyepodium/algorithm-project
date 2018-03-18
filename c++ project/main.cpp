#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: DFS
//사용한 자료구조: 2차원 배열

int d[11][11];
bool check[11][11];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
vector<pair<int, int>> result;

void dfs(int x, int y){
    check[x][y] = true;
  
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=1 && nx<11 && ny>=1 && ny<11){
            if(d[nx][ny] == 0 && d[x][y] == 1){
                cnt++;
            }
        }
    }
    
    if(cnt == 3){
        result.push_back(make_pair(x, y));
    }
    
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=1 && nx<11 && ny>=1 && ny<11){
            if(check[nx][ny] == false && d[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
    
}

int main(){

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            scanf("%1d", &d[i][j]);
        }
    }
    
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            if(check[i][j] == false && d[i][j] == 1){
                dfs(i, j);
            }
        }
    }



    
    if(result.size() == 3){
        vector<double> result2;
        double one, two, three;
        one = sqrt(pow(abs(result[0].first-result[1].first), 2) + pow(abs(result[0].second-result[1].second), 2));
        two = sqrt(pow(abs(result[0].first-result[2].first), 2) + pow(abs(result[0].second-result[2].second), 2));
        three = sqrt(pow(abs(result[1].first-result[2].first), 2) + pow(abs(result[1].second-result[2].second), 2));
        result2.push_back(one);
        result2.push_back(two);
        result2.push_back(three);
        sort(result2.begin(), result2.end());

        cout << pow(result2[0], 2) << endl;
        cout << pow(result2[1], 2) << endl;
        cout << pow(result2[2], 2) << endl;
        
        int one2 = result2[0] * result2[0];
        int two2 = pow(result2[1], 2);
        int three2 = pow(result2[2], 2);

        cout << one2 <<endl;
        cout << two2 << endl;
        cout << three2 << endl;
        
        
        if(pow(result2[0], 2) + pow(result2[1], 2) == pow(result2[2], 2)){
            for(int i=0; i<result.size(); i++){
                cout << result[i].first <<" "<<result[i].second<<endl;
            }
        }else{
            cout << 0 << endl;
        }
        
    }else{
        cout << 0 << endl;
    }
    

}
