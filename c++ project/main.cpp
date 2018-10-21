#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define max_int 21

using namespace std;

//시간 복잡도 계산을 못할거 같은 이유는 인구이동이 끝날때 까지 반복문을 수행하는데
//반복문은 더이상 먹을 수 있는 물고기가 없을 때 종료하잖아... 근데 언제인지 모르겠어
//반복문을 수행나는 횟수를 X라고 하면, 시간복잡도는 O(X*n^2)... 잘 모르겠다

//시간 복잡도: O(X*n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 완전탐색 by BFS, STL sorting
//사용한 자료구조: 그래프 by 2차원 배열


int n, cur_x, cur_y, result, cur_size, cur_eat;
int d[max_int][max_int];
int check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};


struct info{
    int x;
    int y;
    int dist;
};

//먹을 수 있는 물고기 정보를 넣을 벡터 v
vector<info> v;

//먹을 수 있는 물고기를 조건에 따라 정렬한다.
bool cmp(const info &a, const info &b){
    
    if(a.dist == b.dist){
        
        if(a.x == b.x){
            return a.y < b.y;
        }
        else return a.x < b.x;
    }
    else return a.dist < b.dist;
}

//상어의 현재 위치에서 모든 영역의 거리를 계산한다.
void find_dist(int x, int y){
    
    check[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(check[nx][ny] == 0 && d[nx][ny] <= cur_size){
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    
    scanf("%d", &n);
    
    //1. 지도 정보 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &d[i][j]);
            if(d[i][j] == 9){
                cur_x = i;
                cur_y = j;
                d[i][j] = 0;
            }
        }
    }
    
    //처음 시작했을때 상어의 정보 초기화
    //상어의 크기는 2, 먹은 물고기는 0
    cur_size = 2;
    cur_eat = 0;
    
    while(true){
        
        //2. 상어의 현재 위치에서 모든 영역의 거리를 계산한다.
        find_dist(cur_x, cur_y);
        
        //3. 먹을 수 있는 물고기를 찾는다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                //칸에 물고기기 있고, 먹을 수 있을때
                if(d[i][j] > 0 && d[i][j] < cur_size){
                    
                    int dist = check[i][j];
                    
                    //단, 먹을 수 있는 물고기이지만, 큰 물고기에게 둘러쌓여 그 물고기한테 못 갈 수 있다.
                    //갈 수 없는 경우에는 넣지 않는다.
                    if(dist > 0) v.push_back({i, j, dist});
                }
            }
        }

        
        //4. 상어 이동
        int fish_cnt = (int)v.size();
        
        //1) 먹을 수 있는 물고기가 없다면 종료
        if(fish_cnt == 0){
            break;
        }
        else{
            
            //2) 먹을 수 있는 물고기가 1마리보다 많을때
            if(fish_cnt > 1) sort(v.begin(), v.end(), cmp);
            
            int nx = v[0].x;
            int ny = v[0].y;
            int move_time = v[0].dist;
            
            //상어 크기 업데이트
            cur_eat++;
            if(cur_eat == cur_size){
                cur_eat = 0;
                cur_size++;
            }
            
            //상어의 위치 업데이트
            cur_x = nx;
            cur_y = ny;
            
            //지도 변경
            d[nx][ny] = 0;
            
            //물고지 정보 초기화
            v.clear();
            
            //체크 배열 초기화
            memset(check, 0, sizeof(check));
            
            //시간 업데이트
            result += move_time;
        }
    }
    printf("%d\n", result);
    
}

