#include <iostream>
#include <vector>

using namespace std;

int n, m, h;
int d[31][11];
int test[31][11];
int result = -1;

struct info{
    int a;
    int b;
};

vector<info> can_pick;
int can_pick_size = 0;

int pick_size = 0;

//사다리 구현
bool find(int x, int y){
    
    int start_y = y;
    while(x <= h+1){

        //오른쪽 이동
        if(test[x][y] == 1){
            x = x+1;
            y = y+1;
            
            //왼쪽 이동
        }else if(test[x][y] == 2){
            x = x+1;
            y = y-1;
        }else{
            x = x+1;
            y = y;
        }
    }

    bool is_possible = false;
    if(start_y == y){
        is_possible = true;
    }
    
    return is_possible;
}

void test_init(){
    for(int i=1; i<=h; i++){
        for(int j=1; j<=n; j++){
            test[i][j] = d[i][j];
        }
    }
}

void test0(){
    
    test_init();
    
    bool is_possible = true;
    for(int i=1; i<=n; i++){
        if(find(1, i) == false){
            is_possible = false;
            break;
        }
    }
    
    if(is_possible == true){
        result = 0;
    }
    
}

void test1(vector<info> &pick){
    
    test_init();
    
    int x1 = pick[0].a;
    int y1 = pick[0].b;
    int y2 = pick[0].b + 1;
    
    test[x1][y1] = 1;
    test[x1][y2] = 2;
    
    bool is_possible = true;
    for(int i=1; i<=n; i++){
        if(find(1, i) == false){
            is_possible = false;
            break;
        }
    }
    
    if(is_possible == true){
        result = 1;
    }
    
}

void test2(vector<info> &pick){
    
    test_init();
    
    for(int i=0; i<pick.size(); i++){
        int x1 = pick[i].a;
        int y1 = pick[i].b;
        int y2 = pick[i].b + 1;
        test[x1][y1] = 1;
        test[x1][y2] = 2;
    }
    
    bool is_possible = true;
    for(int i=1; i<=n; i++){
        if(find(1, i) == false){
            is_possible = false;
            break;
        }
    }
    
    if(is_possible == true){
        result = 2;
    }
    
}

void test3(vector<info> &pick){
    
    test_init();
    
    for(int i=0; i<pick.size(); i++){
        int x1 = pick[i].a;
        int y1 = pick[i].b;
        int y2 = pick[i].b + 1;
        test[x1][y1] = 1;
        test[x1][y2] = 2;
    }
    
    bool is_possible = true;
    for(int i=1; i<=n; i++){
        if(find(1, i) == false){
            is_possible = false;
            break;
        }
    }
    
    if(is_possible == true){
        result = 3;
    }
    
}

int main(){
    
    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[a][b+1] = 2;
    }
    
    //추가할 수 있는 가로선의 정보를 can_pick 벡터에 넣는다.
    for(int i=1; i<=h; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == 0 && d[i][j+1] == 0 && j+1 <=n){
                can_pick.push_back({i, j});
            }
        }
    }
    
    //전체에서 뽑을 수 있는 것의 수 갱신
    can_pick_size = (int)can_pick.size();
    
    //0개 고름
    test0();
    
    //1개 고름, 고를 수 있는게 1개보다 많아야해
    if(result != 0 && can_pick_size >=1){
        for(int i=0; i<can_pick_size; i++){
            vector<info> pick;
            pick.push_back({can_pick[i].a, can_pick[i].b});
            test1(pick);
            
        }
    }
     
    //2개 고름, 고를 수 있는게 2개보다 많아야해
    if(result !=0 && result != 1 && can_pick_size >=2){
        for(int i=0; i<can_pick_size; i++){
            for(int j=i+1; j<can_pick_size; j++){

                vector<info> pick;
                pick.push_back({can_pick[i].a, can_pick[i].b});
                pick.push_back({can_pick[j].a, can_pick[j].b});
                test2(pick);
                
            }
        }
    }
    
    //3개 고름, 고를 수 있는게 3개보다 많아야해
    if(result !=0 && result != 1 && result != 2 && can_pick_size >=3){
        for(int i=0; i<can_pick_size; i++){
            for(int j=i+1; j<can_pick_size; j++){
                for(int k=j+1; k<can_pick_size; k++){
       
                    vector<info> pick;
                    pick.push_back({can_pick[i].a, can_pick[i].b});
                    pick.push_back({can_pick[j].a, can_pick[j].b});
                    pick.push_back({can_pick[k].a, can_pick[k].b});
                    test3(pick);
                    
                }
            }
        }
    }

    
    cout << result << endl;
    
}
