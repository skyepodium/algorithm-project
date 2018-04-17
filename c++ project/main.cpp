#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(200C3*200 + 3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 순열, prev_permutation
//사용한 자료구조: 2차원 배열, 1차원 벡터

int n, m;

//같이 먹으면 안되는 조합의 정보를 저장하기 위한 2차원 배열
bool no_pick[201][201];

int result = 0;

//같이 먹으면 안되는 조합 검사
void do_test(vector<int> &pick){
    
    bool is_possible = true;
    
    //같이 먹으면 안되는 조합은 2개이므로 간단히 2중 for문으로 검사한다.
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            //만약 2차원 배열에 저장된 정보가 true이면 같이먹으면 안되는 조합
            if(no_pick[pick[i]][pick[j]] == true || no_pick[pick[j]][pick[i]] == true){
                
                //불가능하고, 정보를 갱신한다.
                is_possible = false;
                break;
            }
        }
    }
    
    //검사를 통과하면 방법의 갯수를 1증가 시킨다.
    if(is_possible == true) result++;
}


int main(){

    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        //같이 먹으면 안되는 조합의 정보를 2차원 배열에 저장한다.
        no_pick[a][b] = true;
        no_pick[b][a] = true;
    }

    //순열을 위한 벡터 생성
    vector<int> v;
    
    //전체에서 선택할 3개만큼 1을 넣고
    for(int i=0; i<3; i++){
        v.push_back(1);
    }

    //선택하지 않을 만큼 0을 넣는다.
    for(int i=0; i<n-3; i++){
        v.push_back(0);
    }
    
    //순열 탐색
    do{
        vector<int> pick;

        //v[i] == 1이면 선택이 된것이다.
        for(int i=0; i<n; i++){
            if(v[i] == 1){
                pick.push_back(i+1);
            }
        }
        
        //조합 검사
        do_test(pick);
        
    }while(prev_permutation(v.begin(), v.end()));
 
    cout << result << endl;
}
