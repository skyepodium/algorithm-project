#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 11
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, year;
int a[max_int][max_int];
int d[max_int][max_int];

struct info{
    int x;
    int y;
    int age;
};

vector<info> v;

bool cmp(const info &a, const info &b){
    
    if(a.x == b.x && a.y == b.y){
        return a.age < b.age;
    }
    else{
        if(a.x == b.x){
            return a.y < b.y;
        }
        else{
            return a.x < b.x;
        }
    }
}

int cnt = 0;

int main(){
    scanf("%d %d %d", &n, &m, &year);
    
    //양분입력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            d[i][j] = 5;
        }
    }
    
    //나무 입력
    for(int i=0; i<m; i++){
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        v.push_back({x, y, age});
    }
    
    while(year--){
        //나무 정렬
        sort(v.begin(), v.end(), cmp);
        
        vector<info> alive;
        vector<info> dead;
        vector<info> five;
        vector<info> birth;
        
        //봄
        for(int i=0; i<v.size(); i++){
            
            int x = v[i].x;
            int y = v[i].y;
            int age = v[i].age;
            
            //나무 죽는다.
            if(d[x][y] < age){
                dead.push_back({x, y, age});
            }
            //나무가 양분을 먹는다.
            else{
                //양분 줄고
                d[x][y] -= age;

                //나무 나이 1증가
                v[i].age++;
                
                //살아남은 나무 보관
                alive.push_back({x, y, v[i].age});
                
                //5살 나무 보관
                if(v[i].age%5 == 0) five.push_back({x, y, v[i].age});
            }
            
        }
        
        //여름
        for(int i=0; i<(int)dead.size(); i++){
            int x = dead[i].x;
            int y = dead[i].y;
            int age = dead[i].age;
            int feed = age/2;
            
            d[x][y] += feed;
        }
        
        //가을
        for(int k=0; k<five.size(); k++){
            int x = five[k].x;
            int y = five[k].y;
            
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=1 && nx<=n && ny>=1 && ny<=n){
                    birth.push_back({nx, ny, 1});
                }
            }
        }
        
        //겨울
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j] += a[i][j];
            }
        }
        
        v.clear();
        for(int i=0; i<(int)alive.size(); i++){
            int x = alive[i].x;
            int y = alive[i].y;
            int age = alive[i].age;
            v.push_back({x, y, age});
        }
        
        for(int i=0; i<(int)birth.size(); i++){
            int x = birth[i].x;
            int y = birth[i].y;
            int age = birth[i].age;
            v.push_back({x, y, age});
        }

        alive.clear();
        birth.clear();
        dead.clear();
        five.clear();
        
        cnt = (int)v.size();
    }
    printf("%d\n", cnt);
    
}
