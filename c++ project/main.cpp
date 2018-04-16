#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(2^21)
//공간 복잡도: O(nm)
//사용한 알고리즘: 재귀함수(백트래킹)
//사용한 자료구조: 구조체, 2차원 배열, 1차원 벡터

int h, w;
int n, m;
int result = 2147483647;
int d[8][8];
int test[8][8];
int cctv_size = 0;

//cctv정보를 저장할 구조체
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
    
    //test[i][j]는 검사를 위한 2차원 배열
    //지도 정보를 기반으로 초기화 해준다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
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
    
    //cctv별 4가지 방향을 다 선택해줬으면
    if(index == cctv_size){
        
        //cctv가 감시할 수 없는 사각지대를 검사한다.
        do_test(cctv);
        
        return;
    }
    
    
    //4가지 방향에 대해 선택
    //0은 동쪽, 1은 남쪽, 2는 서쪽, 3은 북쪽
    cctv[index].dir = 0;
    go(index+1, cctv);
    
    cctv[index].dir = 1;
    go(index+1, cctv);
    
    cctv[index].dir = 2;
    go(index+1, cctv);
    
    cctv[index].dir = 3;
    go(index+1, cctv);
}

int main(){
    cin >> n >> m;
    
    //cctv를 넣을 구조체 벡터 생성
    vector<info> cctv;
    
    //n*m 배열에 지도 정보를 입력받는다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            cin >> d[i][j];
            
            //만약 cctv일 경우, cctv 벡터에 넣어준다.
            if(d[i][j] != 0 && d[i][j] != 6){
                cctv.push_back({i, j, 0, d[i][j]});
            }
        }
    }
    
    //cctv 벡터의 크기를 통해 cctv갯수를 갱신해준다.
    cctv_size = (int)cctv.size();
    go(0, cctv);
    
    cout << result << endl;
}
