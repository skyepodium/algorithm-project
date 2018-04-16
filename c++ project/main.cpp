#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
int result;
int d[8][8];
int test[8][8];
int cctv_size = 0;

struct info{
    int x;
    int y;
    int dir;
    int type;
};


void go0(int x, int y){
    
    for(int j=y; j<w; j++){
        if(test[x][j] == 6) break;
        if(test[x][j] == 0) test[x][j] = -1;
    }
    
}

void go1(int x, int y){
    
    for(int i=x; i<h; i++){
        if(test[i][y] == 6) break;
        if(test[i][y] == 0) test[i][y] = -1;
    }
    
}

void go2(int x, int y){
    
    for(int j=y; j>=0; j--){
        if(test[x][j] == 6) break;
        if(test[x][j] == 0) test[x][j] = -1;
    }
}

void go3(int x, int y){
    
    for(int i=x; i>=0; i--){
        if(test[i][y] == 6) break;
        if(test[i][y] == 0) test[i][y] = -1;
    }
}

void do_test(vector<info> &cctv){
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            test[i][j] = d[i][j];
        }
    }
    
    for(int k=0; k<cctv.size(); k++){
        
        if(cctv[k].type == 1){
            if(cctv[k].dir == 0) go0(cctv[k].x, cctv[k].y);
            if(cctv[k].dir == 1) go1(cctv[k].x, cctv[k].y);
            if(cctv[k].dir == 2) go2(cctv[k].x, cctv[k].y);
            if(cctv[k].dir == 3) go3(cctv[k].x, cctv[k].y);
        }
        
        if(cctv[k].type == 2){
            
            if(cctv[k].dir == 0 || cctv[k].dir == 2){
                go0(cctv[k].x, cctv[k].y);
                go2(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 1 || cctv[k].dir == 3){
                go1(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
        }
        
        if(cctv[k].type == 3){
            
            if(cctv[k].dir == 0){
                go2(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 1){
                go0(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 2){
                go0(cctv[k].x, cctv[k].y);
                go1(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 3){
                go1(cctv[k].x, cctv[k].y);
                go2(cctv[k].x, cctv[k].y);
            }
        }
        
        if(cctv[k].type == 4){
            
            if(cctv[k].dir == 0){
                go0(cctv[k].x, cctv[k].y);
                go1(cctv[k].x, cctv[k].y);
                go2(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 1){
                go1(cctv[k].x, cctv[k].y);
                go2(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 2){
                go0(cctv[k].x, cctv[k].y);
                go2(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
            
            if(cctv[k].dir == 3){
                go0(cctv[k].x, cctv[k].y);
                go1(cctv[k].x, cctv[k].y);
                go3(cctv[k].x, cctv[k].y);
            }
        }
        
        if(cctv[k].type == 5){
            go0(cctv[k].x, cctv[k].y);
            go1(cctv[k].x, cctv[k].y);
            go2(cctv[k].x, cctv[k].y);
            go3(cctv[k].x, cctv[k].y);
        }
        
    }
    
    int cnt = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(test[i][j] == 0) cnt++;
        }
    }
    
    result = min(result, cnt);
}

void go(int index, vector<info> &cctv){
    
    if(index == cctv_size){
        
        do_test(cctv);
        
        return;
    }
    
    cctv[index].dir = 0;
    go(index+1, cctv);
    
    cctv[index].dir = 1;
    go(index+1, cctv);
    
    cctv[index].dir = 2;
    go(index+1, cctv);
    
    cctv[index].dir = 3;
    go(index+1, cctv);
}

int main(int argc, char** argv)
{
    result = 99999999;
    cin >> h >> w;
        
    vector<info> cctv;
        
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> d[i][j];
            if(d[i][j] != 0 && d[i][j] != 6){
                    cctv.push_back({i, j, 0, d[i][j]});
            }
        }
    }
        
    cctv_size = (int)cctv.size();
    go(0, cctv);
        
    cout << result << endl;
}
