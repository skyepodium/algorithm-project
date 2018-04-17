#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: stl sort
//사용한 자료구조: 구조체, 1차원 벡터

//회의실 정보를 저장할 구조체 생성
struct info{
    int start_day;
    int end_day;
};

//비교 기준
bool cmp(const info &a, const info &b){
    
    //1) 회의실 사용에 대한 정보가 있을때 가장 빨리 끝나는 것을 선택한다.
    if(a.end_day < b.end_day){
        return true;
    
    //2) 회의실 사용이 끝나는 시간이 같을때 가장 먼저 시작하는 것을 고른다.
    }else if(a.end_day == b.end_day){
        
        return a.start_day < b.start_day;
        
    }else{
        return false;
    }
}

int main(){

    int n;
    cin >> n;
    
    //회의실 정보를 저장할 벡터 plan 생성
    vector<info> plan;
    //입력 정보를 plan벡터에 넣는다.
    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        
        plan.push_back({start, end});
    }
    
    //stl sort 사용, cmp는 기준
    sort(plan.begin(), plan.end(), cmp);
    
    int cnt = 0;
    int current = -1;
    //회의실 사용정보를 선형 탐색
    //가장빠른것 부터 취하고, 이후에는 일정이 겹치지 않으면 취한다.
    for(int i=0; i<plan.size(); i++){
        if(plan[i].start_day >= current){
            current = plan[i].end_day;
            cnt++;
        }
    }
    
    cout << cnt << endl;
}

