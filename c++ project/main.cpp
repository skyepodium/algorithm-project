#include <iostream>
#include <vector>

using namespace std;

//call by reference로 벡터 받음
void go(int index, vector<int> &pick){
    
    //길이가 3개이기 때문에 index는 0,1,2가 존재
    //index가 3이 되면, 넘어간 것이므로 재귀종료
    if(index == 3){
        
        //3개 다 골랐을때 벡터의 내용을 출력
        for(int i=0; i<pick.size(); i++){
            cout << pick[i] <<" ";
        }
        cout << endl;
        
        return;
    }
    
    //각각의 상황별로 4가지 상황이 있다. 0~3
    for(int i=0; i<4; i++){
        //넣어주면, 재귀함수에 의해 다시 돌아왔을때 넣은 것을 꼭 빼줘야한다.
        pick.push_back(i);
        go(index+1, pick);
        pick.pop_back();
    }
    
}


int main(){
    
    vector<int>pick;
    //index 0부터 시작,
    //빈 벡터를 함께 보내준다.
    go(0, pick);
}
