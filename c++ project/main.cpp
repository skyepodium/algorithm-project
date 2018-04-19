#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O()
//공간 복잡도: O(10000)
//사용한 알고리즘: 반복문
//사용한 자료구조: 스택(1차원 벡터), 2차원 배열, 1차원 배열

bool map[102][102];
int end_x = 0;
int end_y = 0;
int n;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> dragon;

void make_generation(vector<int> &dragon){
    
    int size = (int)dragon.size();

    for(int i=size-1; i>=0; i--){
        int dir = (dragon[i] + 1)%4;
        
        end_x = end_x + dx[dir];
        end_y = end_y + dy[dir];
        
        map[end_x][end_y] = true;
        
        dragon.push_back(dir);
    }
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        int y, x, d, g;
        cin >> y >> x >> d >> g;
        dragon.clear();
        
        end_x = x;
        end_y = y;
        map[end_x][end_y] = true;
        
        //0세대는 미리 만들어 놓는다.
        end_x = x + dx[d];
        end_y = y + dy[d];
        map[end_x][end_y] = true;
        dragon.push_back(d);

        //세대를 만들어보자
        for(int i=0; i<g; i++){
            make_generation(dragon);
        }
        
    }
    
    int result = 0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            
            if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1] == true){
                    result++;
            }
        }
    }
    
    cout << result << endl;
    
}
