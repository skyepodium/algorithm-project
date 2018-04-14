#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int d[8][8];
bool check[8][8];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct position{
    int x;
    int y;
    bool used;
    int height;
    int dist;
};

int result = 0;

void dfs(position cur){
    result = max(result, cur.dist);
    check[cur.x][cur.y] = true;
    
    for(int i=0; i<4; i++){
        
        position next = cur;
        next.x = next.x + dx[i];
        next.y = next.y + dy[i];
        next.height = d[next.x][next.y];
        
        if(next.x>=0 && next.x<n && next.y>=0 && next.y<n){
            if(check[next.x][next.y] == false){
                
                if(next.height < cur.height){
                    next.dist++;
                    dfs(next);
                }else{
                
                    if(cur.used == false && next.height - k <cur.height){
                        next.height = cur.height - 1;
                        next.used = true;
                        next.dist++;
                        dfs(next);
                    }
                }
            }
        }
    }
    
    check[cur.x][cur.y] = false;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> k;
        result = 0;
        int max_height = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
                max_height = max(max_height, d[i][j]);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] == max_height){
                    position cur = {i, j, false, max_height, 1};
                    dfs(cur);
                }
            }
        }
        
        
        cout << "#" << test_case << " " <<result << endl;
        
    }
    return 0;
}
