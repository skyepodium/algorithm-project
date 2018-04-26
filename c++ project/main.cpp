#include <iostream>

using namespace std;

//시간 복잡도: O(루트 n)
//공간 복잡도: 0
//사용한 알고리즘: 선형 탐색
//사용한 자료구조: 없음

int main(){
    
    int n;
    cin >> n;
    
    int cnt = 0;
    bool is_check = false;
    
    //루트n까지만 for문을 돌린다.
    for(int i=1; i*i<=n; i++){
        
        //나누어서 0이되는 수가 있으면 갯수를 1증가시킨다.
        if(n%i == 0) cnt++;
        
        //제곱해서 n이 되는 수가 있으면 체크해준다.
        if(i*i == n) is_check = true;
        
    }
    
    int result = 0;
    //제곱해서 n이 되는 수가 있으면
    if(is_check == true) result = (cnt-1) * 2 + 1;
    
    //없으면
    else result = cnt*2;
    
    cout << result << endl;
    
}

