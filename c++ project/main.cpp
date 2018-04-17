#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 3중 for문
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

    //nC3을 위한 3중 for문
    for(int a=1; a<=n; a++){
        for(int b=a+1; b<=n; b++){
            for(int c=b+1; c<=n; c++){

                //선택한 정보를 넣을 벡터 pick생성
                vector<int> pick;

                //선택한 정보를 pick벡터에 넣는다.
                pick.push_back(a);
                pick.push_back(b);
                pick.push_back(c);
                
                //선택한 조합을 넘겨 조합 가능여부를 검사한다.
                do_test(pick);
                
            }
        }
    }
    
    
    cout << result << endl;
}
