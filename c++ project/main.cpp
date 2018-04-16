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

//최대값 안주어졌기 때문에 정수 최대값 넣었다.
int result = 2147483647;

//집별로 치킨거리 계산
void chicken_dist(vector<pair<int, int>> &pick){
    
    int total_dist = 0;
    //집별로 돌고
    for(int i=0; i<house.size(); i++){
        int x = house[i].first;
        int y = house[i].second;
        int dist = 2147483647;
        
        //m개의 치킨집 조사
        for(int j=0; j<pick.size(); j++){
            
            int nx = pick[j].first;
            int ny = pick[j].second;
            int ndist = abs(nx-x) + abs(ny-y);
            
            //집별 치킨 거리갱신
            dist = min(dist, ndist);
        }
        
        total_dist += dist;
    }
    
    //도시의 최소 치킨거리를 갱신한다.
    result = min(result, total_dist);
    
}

//도시의 최대 치킨집 갯수에 대해 각각에 대해 선택한것을 pick에 넣는다.
void go(int index, vector<pair<int, int>> &pick){
    
    if(index == max_chicken){
        //조합이 갖춰지면
        if((int)pick.size() == m){
            //치킨거리를 계산한다.
            chicken_dist(pick);
        }
        return;
    }
    
    //치킨집 고름
    pick.push_back(make_pair(chicken[index].first, chicken[index].second));
    go(index+1, pick);
    pick.pop_back();

    //치킨집 안고름
    go(index+1, pick);
}

int main(){
    
    cin >> n >> m;
    
    //지도정보를 입력받는다.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
            //집일 경우 house 벡터에 넣고
            if(d[i][j] == 1) house.push_back(make_pair(i, j));
            
            //치킨집일 경우 chicken벡터에 넣는다.
            if(d[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    
    //치킨 벡터의 크기를 통해 도시에 있는 최대 치킨집의 갯수를 갱신한다.
    max_chicken = (int)chicken.size();
    
    
    //치킨집을 선태해서 저장할 pick벡터
    vector<pair<int, int>> pick;
    
    //조합을 위한 백트래킹 시작
    go(0, pick);
    
    cout << result << endl;
    
}
