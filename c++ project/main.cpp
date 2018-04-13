#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

//x좌표, y좌표, 시간
//total_mi 는 해당 좌표, 해당 시간의 총 미생물 수 합
//max_mi 는 해당 좌표, 해당 시간의 미생물 최대 크기

int total_mi[101][101][1000];
int max_mi[101][101][1000];

struct mi{
    int x;
    int y;
    int num;
    int dir;
};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m >> k;
        
        vector<mi> v;
        
        for(int i=0; i<k; i++){
            int x, y, num, dir;
            cin >> x >> y >> num >> dir;
            
            //방향 정보 수정 dx[],dy[] 사용하기 위함
            if(dir == 1) dir = 0;
            else if(dir == 4) dir = 1;
            else if(dir == 2) dir = 2;
            else dir = 3;
            
            //미생물 총, 최대, 방향 갱신
            total_mi[x][y][0] = num;
            max_mi[x][y][0] = num;
            
            v.push_back( {x, y, num, dir });
        }
    
        //격리 시간 for문 수행 시작
        for(int time_index = 1; time_index <= m; time_index++){

            //미생물들을 벡터에서 하나씩 조사 시작
            for(int i=0; i<v.size(); i++){
                
                //다른 미생물과 만나서 합체했으면 건너뛴다.
                if(v[i].num  == 0) continue;
                
                //먼저 있었는데 합쳐진 경우
                if(max_mi[v[i].x][v[i].y][time_index-1] != v[i].num){
                    v[i].num = 0;
                    continue;
                    
                //나중에 들어갔는데 나보다 큰 미생물때문에 총합이 변경된 경우
                }else{
                    v[i].num = total_mi[v[i].x][v[i].y][time_index-1];
                }
                
                
                //현재 방향에서 한칸 이동
                int nx = v[i].x + dx[v[i].dir];
                int ny = v[i].y + dy[v[i].dir];
                
                //일단 먼저 이동 이동시킨다. 이동 후 검사한다.
                v[i].x = nx;
                v[i].y = ny;

                
                //만약 이동한 구역이 빨간 구역이라면
                if(nx == 0 || ny == n-1 || ny == 0 || ny == n-1){

                    //반대 방향으로 갱신
                    v[i].dir = (v[i].dir + 2)%4;
                    
                    //미생물 절반 죽임
                    v[i].num = v[i].num/2;
                    if(v[i].num == 1) v[i].num = 0;
                    
                    //만약 이동한 빨간 구역에 미생물이 존재한다면.
                    if(total_mi[nx][ny][time_index] > 0){
                        
                        //이동한 빨간 구역의 최대 미생물이 내꺼보다 크다면
                        if(max_mi[nx][ny][time_index] > v[i].num){
                            
                            //전체 미생물 갱신해주고
                            total_mi[nx][ny][time_index] += v[i].num;
                            
                            //내 미생물 없앤다.
                            v[i].num = 0;
                            cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;

                            
                        //이동한 빨간 구역의 미생물이 내꺼보다 작다면
                        }else{
                            //전체 미생물 갱신해주고
                            total_mi[nx][ny][time_index] += v[i].num;
                            
                            //내 미생물의 수는 전체 미생물 수이다.
                            v[i].num = total_mi[nx][ny][time_index];
                            max_mi[nx][ny][time_index] = v[i].num;
                            
//                            cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;

                        }
                    }else{
                    
                        //빨간 구역 미생물 없을때
                        total_mi[nx][ny][time_index] = v[i].num;
                        max_mi[nx][ny][time_index] = v[i].num;
//                        cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;
                    }
                }
                //빨간 구역 수행 종료
                
                
                // 빨간 구역이 아니라면
                else{
                    
                    //만약 이동한 구역에 미생물이 존재한다면.
                    if(total_mi[nx][ny][time_index] > 0){
                        
                        //이동한 구역의 최대 미생물이 내꺼보다 크다면
                        if(max_mi[nx][ny][time_index] > v[i].num){
                            
                            //전체 미생물 갱신해주고
                            total_mi[nx][ny][time_index] += v[i].num;
                            
                            //내 미생물 없앤다.
                            v[i].num = 0;
                        
//                            cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;
                            
                        //이동한 구역의 미생물이 내꺼보다 작다면
                        }else{
                            //전체 미생물 갱신해주고
                            total_mi[nx][ny][time_index] += v[i].num;
                            
                            //내 미생물의 수는 전체 미생물 수이다.
                            v[i].num = total_mi[nx][ny][time_index];
                            max_mi[nx][ny][time_index] = v[i].num;
//                            cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;
                        }
                    }else{
                    
                        //빨간구역 아닌거 미생물 없을때
                        total_mi[nx][ny][time_index] = v[i].num;
                        max_mi[nx][ny][time_index] = v[i].num;
//                        cout << "time_index " <<time_index<<" mi_index "<< i<<"  "<<v[i].x << " " << v[i].y << " " << v[i].num << endl;
                    }
                }
                // 빨간 구역 아닌거 수행 종료
                
            }
            //미생물들을 벡터에서 하나씩 조사 종료
            
        }
        //격리 시간 for문 수행 종료

        //미생물 수 출력
        int result = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].num > 0){
                result = result + v[i].num;
            }
        }
        cout << "#" << test_case << " "<< result << endl;
        
        v.clear();
        memset(total_mi, 0, sizeof(total_mi));
        memset(max_mi, 0, sizeof(max_mi));
    }
    return 0;
}
