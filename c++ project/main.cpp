#include <iostream>
#include <queue>
#define max_int 3001

using namespace std;

int n, m, start_x, start_y, left_cnt, right_cnt, result;
bool check[max_int][max_int];
char a[max_int][max_int];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct info{
    int x, y, l_cnt, r_cnt;
};

struct cmp{
    bool operator()(const info &a, const info &b){
        if(a.l_cnt == b.l_cnt){
            return a.r_cnt < b.r_cnt;
        }
        else{
            return a.l_cnt < b.l_cnt;
        }
    }
};

void bfs(){
    priority_queue<info, vector<info>, cmp> pq;
    check[start_x][start_y] = true;
    result++;
    pq.push({start_x, start_y, left_cnt, right_cnt});
    
    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();
        
        int x = cur.x;
        int y = cur.y;
        int l_cnt = cur.l_cnt;
        int r_cnt = cur.r_cnt;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx > n || nx < 1 || ny > m || ny < 1) continue;
            if(check[nx][ny] || a[nx][ny] == '*')  continue;
            
            if(i == 2){
                if(l_cnt == 0) continue;
                check[nx][ny] = true;
                result++;
                pq.push({nx, ny, l_cnt - 1, r_cnt});
            }
            else if(i == 3){
                if(r_cnt == 0) continue;
                check[nx][ny] = true;
                result++;
                pq.push({nx, ny, l_cnt, r_cnt - 1});
            }
            else{
                check[nx][ny] = true;
                result++;
                pq.push({nx, ny, l_cnt, r_cnt});
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    scanf("%d %d", &start_x, &start_y);
    
    scanf("%d %d", &left_cnt, &right_cnt);
    
    for(int i=1; i<=n; i++){
        scanf("%s", a[i] + 1);
    }
    
    bfs();
    
    printf("%d\n", result);
}
