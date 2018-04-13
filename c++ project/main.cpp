#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[101][101];
bool check[101][101];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int a[101][101][1000];

struct mi{
  
    int x;
    int y;
    int num;
    int dir;
    bool is_alive;
};

bool cmp(const mi &a, const mi &b){

    if(a.num < b.num){
        return false;
    }else{
        return true;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int n, m, k;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        cin >> n >> m >> k;
        
        vector<mi> v;
        
        for(int i=0; i<k; i++){
            int x, y, num, dir;
            cin >> x >> y >> num >> dir;
            if(dir == 1) dir = 0;
            else if(dir == 4) dir = 1;
            else if(dir == 2) dir = 2;
            else dir = 3;
            a[x][y][0] = num;
            v.push_back( {x, y, num, dir, true });
        }
        
        
        for(int time_index = 1; time_index<=m; time_index++){
        
            //미생물 수가 작은 것부터 오름차순 정렬
//            sort(v.begin(), v.end(), cmp);
            
            
            for(int i=0; i<v.size(); i++){
                
                if(v[i].is_alive == true){
                
                    //이동 시킴
                    v[i].num = a[v[i].x][v[i].y][time_index-1];
                    a[v[i].x][v[i].y][time_index-1] = 0;
                    v[i].x = v[i].x + dx[v[i].dir];
                    v[i].y = v[i].y + dy[v[i].dir];

                    //빨간 영역 들어감
                    if(v[i].x == 0 || v[i].x == n-1 || v[i].y == 0 || v[i].y == n-1){
                        //절반 죽음
                        v[i].num /= 2;
                    
                        //방향 반대로 바뀜
                        v[i].dir = (v[i].dir + 2)%4;
                    }
                    
                    // 이동하려는 자리에 미생물이 존재한다.
                    if(a[v[i].x][v[i].y][time_index] > 0){
                    
                        //이동하려는 자리의 미생물이 나보다 많다.
                        if(a[v[i].x][v[i].y][time_index] > v[i].num){
                            a[v[i].x][v[i].y][time_index] += v[i].num;
                            v[i].is_alive = false;
                            v[i].num = 0;
                        }
                    }else{
                        a[v[i].x][v[i].y][time_index] = v[i].num;
                    }
                }
            }
        }
        int result = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].is_alive == true){
                result = result + v[i].num;
            }
        }
        cout << "#" << test_case <<" "<<result << endl;
    }
    return 0;
}
