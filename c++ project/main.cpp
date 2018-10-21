#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define max_int 21

using namespace std;

int n;
int cur_size = 2;
int cur_eat = 0;

int cur_x, cur_y;
int d[max_int][max_int];
int result;
int check[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};


struct info{
    int x;
    int y;
    int dist;
};

vector<info> v;

bool cmp(const info &a, const info &b){
    
    if(a.dist == b.dist){
        
        if(a.x == b.x){
            return a.y < b.y;
        }
        else return a.x < b.x;
    }
    else return a.dist < b.dist;
}

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
    
    while(true){
        
        //2. 물고기의 위치를 찾는다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] > 0 && d[i][j] < cur_size){
                    
                    find_dist(cur_x, cur_y);
                    
                    int dist = check[i][j];
                    if(dist > 0)v.push_back({i, j, dist});
                    memset(check, 0, sizeof(check));
                }
            }
        }
        
        //3. 상어 이동
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
            
            //변수 초기화
            v.clear();
            
            //시간 업데이트
            result += move_time;
        }
    }
    printf("%d\n", result);
    
}

