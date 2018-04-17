#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(????, 알아올께요)
//공간 복잡도: O(nh)
//사용한 알고리즘: n중 for문
//사용한 자료구조: 구조체, 1차원 벡터, 2차원 배열

int n, m, h;
int d[31][11];
int test[31][11];
int result = -1;

//가로선 정보를 저장할 구조체 생성
struct info{
    int a;
    int b;
};

//가로선을 놓을 수 있을때 그 정보를 can_pick 벡터에 넣는다.
vector<info> can_pick;
int can_pick_size = 0;


//사다리 타기 구현
bool find(int x, int y){
    
    int start_y = y;
    while(x <= h+1){
        
        //오른쪽 이동
        //한칸 내려갔는데, 가로선의 시작점이다.
        //그러면 가로선 타고 오른쪽으로 이동후 한칸 내려간다.
        if(test[x][y] == 1){
            x = x+1;
            y = y+1;
            
        //왼쪽 이동
        //한칸 내려갔는데, 가로선의 끝점이다.
        //그러면 가로선 타고 왼쪽으로 이동후 한칸 내려간다.
        }else if(test[x][y] == 2){
            x = x+1;
            y = y-1;
            
        //아래로 이동
        //가로선이 없으면 아래로 한칸 내려간다.
        }else{
            x = x+1;
            y = y;
        }
    }
    
    bool is_possible = false;
    
    //시작점과, 끝점의 세로선이 같다면
    if(start_y == y){
        is_possible = true;
    }
    
    return is_possible;
}

//테스트를 위해 기존 지도 정보를 test 2차원 배열에 넣는다.
void test_init(){
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=n; j++){
            test[i][j] = d[i][j];
        }
    }
    
}


//가로선 놓고 검사실행
void do_test(vector<info> &pick){
    
    //테스트를 위해 2차원 배열 생성
    test_init();
    
    //가로선 놓는다.
    for(int i=0; i<pick.size(); i++){
        int x1 = pick[i].a;
        int y1 = pick[i].b;
        int y2 = pick[i].b + 1;
        test[x1][y1] = 1;
        test[x1][y2] = 2;
    }
    
    //for문으로 n개의 가로선 모두 검사한다.
    bool is_possible = true;
    for(int i=1; i<=n; i++){
        if(find(1, i) == false){
            is_possible = false;
            break;
        }
    }
    
    //검사를 통과했다면, 놓은 가로선의 수를 갱신한다.
    if(is_possible == true){
        result = (int)pick.size();
    }
    
}

int main(){
    
    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        //가로선의 정보를 2차원 배열에 넣는다.
        //1은 왼쪽 시작점, 2는 오른쪽 끝점
        d[a][b] = 1;
        d[a][b+1] = 2;
    }
    
    //2차원 배열에서 가로선을 놓을 수 있는 위치를 검사한다.
    //추가할 수 있는 가로선의 정보를 can_pick 벡터에 넣는다.
    for(int i=1; i<=h; i++){
        for(int j=1; j<=n; j++){
            
            //왼쪽, 오른쪽 둘다 기존에 가로선이 없으면 가로선을 넣을 수 있다.
            if(d[i][j] == 0 && d[i][j+1] == 0 && j+1 <=n){
                can_pick.push_back({i, j});
            }
        }
    }
    
    //전체에서 뽑을 수 있는 수 갱신
    can_pick_size = (int)can_pick.size();
    
    
    //0개 고름, 검사해본다.
    vector<info> pick;
    do_test(pick);
    
    
    //1개 고름, 고를 수 있는게 1개보다 많아야한다.
    if(result != 0 && can_pick_size >=1){
        for(int i=0; i<can_pick_size; i++){
          
            vector<info> pick;
            pick.push_back({can_pick[i].a, can_pick[i].b});
            do_test(pick);
            
        }
    }
    
    
    //2개 고름, 고를 수 있는게 2개보다 많아야한다.
    if(result !=0 && result != 1 && can_pick_size >=2){
        for(int i=0; i<can_pick_size; i++){
            for(int j=i+1; j<can_pick_size; j++){
                
                vector<info> pick;
                pick.push_back({can_pick[i].a, can_pick[i].b});
                pick.push_back({can_pick[j].a, can_pick[j].b});
                do_test(pick);
                
            }
        }
    }
    
    
    //3개 고름, 고를 수 있는게 3개보다 많아야한다.
    if(result !=0 && result != 1 && result != 2 && can_pick_size >=3){
        for(int i=0; i<can_pick_size; i++){
            for(int j=i+1; j<can_pick_size; j++){
                for(int k=j+1; k<can_pick_size; k++){
                    
                    vector<info> pick;
                    pick.push_back({can_pick[i].a, can_pick[i].b});
                    pick.push_back({can_pick[j].a, can_pick[j].b});
                    pick.push_back({can_pick[k].a, can_pick[k].b});
                    do_test(pick);
                    
                }
            }
        }
    }
    
    
    cout << result << endl;
    
}

