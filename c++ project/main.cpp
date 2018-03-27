#include <iostream>
#include <queue>

using namespace std;

int d[31][31][31];
bool check[31][31][31];
int l, r, c;
int dir[6][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };

struct s{
    int h;
    int x;
    int y;
};

void bfs(int h, int x, int y){
    
    check[h][x][y] = true;
    queue<s> q;
    q.push( {h, x, y});
    
    while(!q.empty()){
        h = q.front().h;
        x = q.front().x;
        y = q.front().y;
        q.pop();
        
        for(int i=0; i<6; i++){
            int n_h = h + dir[i][0];
            int n_x = x + dir[i][1];
            int n_y = y + dir[i][2];
            
            if(n_h>=0 && n_h<l && n_x >= 0 && n_x < r && n_y>=0 && n_y<c){
                if(check[n_h][n_x][n_y] == false && d[n_h][n_x][n_y] == 0){
                    
                    check[n_h][n_x][n_y] = true;
                    q.push({n_h, n_x, n_y});
                    d[n_h][n_x][n_y] = d[h][x][y] + 1;
                }
            }
        }
    }
}


void clear(){
    
    for(int i=0; i<l; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                d[i][j][k] = 0;
                check[i][j][k] = false;
            }
        }
    }
    
}

int main(){
    
    while(true){
        cin >> l >> r >> c;
        if(l == 0 && r== 0 && c==0){
            break;
        }

        int start_h = 0, start_x = 0, start_y = 0;
        int end_h = 0, end_x = 0, end_y = 0;
        
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    char c;
                    cin >> c;
                    if(c == '.') d[i][j][k] = 0;
                    else if (c == '#') d[i][j][k] = 1;
                    else if (c == 'S'){
                        d[i][j][k] = 0;
                        start_h = i;
                        start_x = j;
                        start_y = k;
                    }
                    else{
                        d[i][j][k] = 0;
                        end_h = i;
                        end_x = j;
                        end_y = k;
                    }
                }
            }
        }
        
        bfs(start_h, start_x, start_y);
        
        if(check[end_h][end_x][end_y] == true){
            cout <<"Escaped in "<<d[end_h][end_x][end_y]<<" minute(s)."<< endl;
        }else{
            cout <<"Trapped!"<<endl;
        }
        
        clear();
        
        
    }
}

