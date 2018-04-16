#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//시간 복잡도: O(m^3*n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 재귀함수(백트래킹)
//사용한 자료구조: 구조체, 2차원 배열, 1차원 벡터

int n, m;
int d[50][50];

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int max_chicken;
int result = 2147483647;

void chicken_dist(vector<pair<int, int>> &pick){
    
    int total_dist = 0;
    
    for(int i=0; i<house.size(); i++){
        int x = house[i].first;
        int y = house[i].second;
        int dist = 2147483647;
        
        for(int j=0; j<pick.size(); j++){
            
            int nx = pick[j].first;
            int ny = pick[j].second;
            int ndist = abs(nx-x) + abs(ny-y);
            dist = min(dist, ndist);
        }
        
        total_dist += dist;
    }
    
    result = min(result, total_dist);
    
}

void go(int index, vector<pair<int, int>> &pick){
    
    if(index == max_chicken){
        
        if((int)pick.size() == m){

            chicken_dist(pick);
        }
        return;
    }
    
    //치킨집 고름
    pick.push_back(make_pair(chicken[index].first, chicken[index].second));
    go(index+1, pick);
    pick.pop_back();

    // 치킨집 안고름
    go(index+1, pick);
}

int main(){
    
    cin >> n >> m;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
            if(d[i][j] == 1) house.push_back(make_pair(i, j));
            if(d[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    
    max_chicken = (int)chicken.size();
    
    vector<pair<int, int>> pick;
    go(0, pick);
    
    cout << result << endl;
    
}
