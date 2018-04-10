#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

//시간 복잡도: O(2^25)
//공간 복잡도: O(25)
//사용한 알고리즘: prev_permutation, bfs
//사용한 자료구조: 2차원 배열


int d[5][5];
int a[5][5];
bool check[5][5];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int result = 0;

void bfs(int x, int y){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<5 && ny>=0 && ny<5){
                if(check[nx][ny] == false && a[nx][ny] == 1){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void clear_check(){
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            a[i][j] = 0;
            check[i][j] = false;
        }
    }
    
}

bool check_cnt(){
    
    bool search_result = false;
    int cnt = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(check[i][j] == true){
                cnt++;
            }
        }
    }
    
    if(cnt == 7){
        search_result = true;
    }
        
    return search_result;
}

int main(){
    
    vector<pair<int, int>> position;
    for(int i=0; i<5; i++){
        string word;
        cin >> word;
        for(int j=0; j<5; j++){
            d[i][j] = word[j];
            position.push_back(make_pair(i, j));
        }
    }
    
    vector<int> v;
    
    for(int i=0; i<7; i++){
        v.push_back(1);
    }
    
    for(int i=0; i<18; i++){
        v.push_back(0);
    }

    do{
        int dasom_cnt = 0;
        int start_x = 0;
        int start_y = 0;
        for(int i=0; i<25; i++){
            if(v[i] == 1){
                if(d[position[i].first][position[i].second] == 83){
                    dasom_cnt++;
                }
                a[position[i].first][position[i].second] = 1;
                start_x = position[i].first;
                start_y = position[i].second;
            }
        }
        
        
        if(dasom_cnt >= 4){
            bfs(start_x, start_y);
        }
        
        if(check_cnt() == true) result++;
        
        clear_check();
        
    }while(prev_permutation(v.begin(), v.end()));
    
    cout << result << endl;
}
