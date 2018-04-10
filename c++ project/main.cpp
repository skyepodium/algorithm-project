#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int result = 0;
int max_height = 0;

int d[10][10];
bool check[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct position{
    int x;
    int y;
    int height;
    bool used;
    int dist;
};

void dfs(position current){
    result = max(result, current.dist);
    
    for(int i=0; i<4; i++){
        position next = current;
        next.x += dx[i];
        next.y += dy[i];
        next.height = d[next.x][next.y];
        
        if(next.x>=0 && next.x<n && next.y>=0 && next.y < n){
            if(check[next.x][next.y] == false){
                
                // 다음 장소가 현재 높이보다 작을 경우
                if(next.height < current.height){
                    check[next.x][next.y] = true;
                    next.dist++;
                    dfs(next);
                    check[next.x][next.y] = false;
                }
                
                else{
                    if(current.used == false && next.height - k < current.height){
                        check[next.x][next.y] = true;
                        next.dist++;
                        next.used = true;
                        next.height = current.height - 1;
                        dfs(next);
                        check[next.x][next.y] = false;
                    }
                }
                
            }
        }
        
        
    }
    
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> k;
        result = max_height = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
                max_height = max(max_height, d[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] == max_height){
                    check[i][j] = true;
                    position cur = {i, j, max_height, false, 1};
                    dfs(cur);
                    check[i][j] = false;
                }
            }
        }
        
        cout << "#" << test_case << " " << result << endl;

        
    }
    return 0;
}
