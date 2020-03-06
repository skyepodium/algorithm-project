#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n*2^g + xy)
//공간 복잡도: O(xy)
//사용한 알고리즘: 반복문
//사용한 자료구조: 스택(1차원 벡터), 2차원 배열, 1차원 배열

bool map[102][102];

//끝점의 정보
int end_x = 0;
int end_y = 0;


//왼쪽, 위쪽, 오른쪽, 아래쪽
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};


//이전 세대의 방향정보를 저장하는 스택
//stl 스택쓰면 귀찮으니까 인덱스로 접근 할 수 있는 벡터를 사용한다.
vector<int> dragon;

//스택을 조사하면서 드래곤 커브를 만드는 함수
void make_generation(vector<int> &dragon){
    
    //현재 스택의 크기를 먼저 계산해 놓는다.
    int size = (int)dragon.size();
    
    //스택의 뒤에서 부터 꺼내면서
    //다음세대의 방향정보를 dir = (dragon[i] + 1)%4; 규칙에 따라 생성한다.
    for(int i=size-1; i>=0; i--){
        int dir = (dragon[i] + 1)%4;
        
        //다음 세대의 방향정보를 바탕으로 다음 x,y를 찾고 이를 갱신한다.
        end_x = end_x + dx[dir];
        end_y = end_y + dy[dir];
        
        //만들어진 드래곤 커브를 지도에 놓아준다.
        map[end_x][end_y] = true;
        
        //다음세대를 위하 스택에 방향정보를 넣어준다.
        dragon.push_back(dir);
    }
}

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        //x, y의 순서를 바꿔서 입력받는다.
        int y, x, d, g;
        scanf("%d %d %d %d", &y, &x, &d, &g);
        
        //기존 드래곤 커브의 스택을 비워준다.
        dragon.clear();
        
        //끝점을 갱신한다.
        end_x = x;
        end_y = y;
        
        //현재 위치에 드래곤 커브가 놓여있으므로 지도에 표시해준다.
        map[end_x][end_y] = true;
        
        //0세대는 미리 만들어 놓는다.
        end_x = x + dx[d];
        end_y = y + dy[d];
        
        //0세대를 만든 이후에도 지도에 표시해준다.
        map[end_x][end_y] = true;
        
        //0세대의 방향정보를 스택에 넣어준다.
        dragon.push_back(d);
        
        //반복문을 통해 0부터 차례차례 드래곤 커브를 만들면서 g세대까지 만든다.
        for(int i=0; i<g; i++){
            
            //드래곤 커브를 만들자
            make_generation(dragon);
        }
        
    }
    
    //100*100 2차원 행렬을 2중 for문 사용한 단순한 탐색
    //인접한 4칸이 모두 true이면, 4칸이 모두 드래곤 커브의 일부인것
    //갯수를 1증가시킨다.
    int result = 0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            
            //인접한 4칸의 정사각형이 모두 드래곤의 일부이면
            if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1] == true){
                
                //갯수를 1 증가시킨다.
                result++;
            }
        }
    }
    
    //갯수 출력
    printf("%d\n", result);
    
}
