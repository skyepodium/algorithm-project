#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define max_int 51

using namespace std;

//시간 복잡도 계산을 못할거 같은 이유는 인구이동이 끝날때 까지 반복문을 수행하는데
//인구이동이 언제 끝날지 모르겠어 그게 답이잖아.
//인구이동이 일어나는 횟수를 X라고 하면, 시간복잡도는 O(X*n^2)... 잘 모르겠다

//시간 복잡도: O(X*n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 완전탐색, 플러드 필 by BFS
//사용한 자료구조: 그래프 by 2차원 배열


int n, l, r, people_num, area_cnt;
int d[max_int][max_int];
bool check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int result = 0;
bool is_move = false;
vector<pair<int, int>> v;


void check_area(int x, int y){

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int diff = abs(d[nx][ny] - d[x][y]);
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == false && diff>=l && diff<=r){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void union_area(int x, int y){
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = false;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        v.push_back(make_pair(x, y));
        people_num += d[x][y];
        area_cnt += 1;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int diff = abs(d[nx][ny] - d[x][y]);
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == true && diff>=l && diff<=r){
                    check[nx][ny] = false;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void dist_people(){
    int after_people = people_num/area_cnt;
    for(int i=0; i<(int)v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        d[x][y] = after_people;
    }
    is_move = true;
}

int main(){
    scanf("%d %d %d", &n, &l, &r);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &d[i][j]);
        }
    }
    
    while(true){
        
        //1. bfs로 돌면서 인구이동이 발생할 나라들을 체크해놓는다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == false){
                    check_area(i, j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //위에서 체크한 내용을 거꾸로 이용한다.
                //true -> false로
                if(check[i][j] == true){
                    
                    //사용할 변수 초기화
                    people_num = 0;
                    area_cnt = 0;
                    v.clear();
                    
                    //2. 플러드 필을 이용해서 연합을 만든다.
                    union_area(i, j);

                    //3. 인구 분배
                    dist_people();
                }
            }
        }

        //인구이동이 일어나지 않았다면 종료시킨다.
        if(is_move == false) break;
        //인구이동이 일어났다면 인구이동 += 1
        else result++;

        //변수 초기화
        is_move = false;
        memset(check, false, sizeof(check));
    }
    printf("%d\n", result);
}

