#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(logn)
//공간 복잡도: O(n)
//사용한 알고리즘: while문
//사용한 자료구조: 1차원 벡터


int main(){
    
    //n, b를 입력받는다.
    int n, b;
    cin >> n >> b;
    
    //결과를 저장할 벡터 result 선언
    //문자도 섞여있기 때문에 char로 선언해준다.
    vector<char> result;
    
    //일반적인 진법변환과 같은 방식으로 진행한다.
    while(n > 0){
        
        //나머지가 10보다 작을때는 정수형태로 출력한다.
        //아스키코드에서 0은 48, 따라서 48을 더해준다.
        if(n%b < 10){
            
            result.push_back(n%b + 48);
        
        //나머지가 10보다 크거나 같을때는 알파벳 대문자로 출력한다.
        //아스키코드에서 알파벳A는 65, 따라서 55를 더해준다.
        }else{
            result.push_back(n%b + 55);
        }
        
        //다음을 위해 n으로 나눠주고 갱신한다.
        n = n/b;
    }
    
    //뒤에서 부터 출력
    for(int i = (int)result.size() - 1; i>=0; i--){
        cout << result[i];
    }
    cout << endl;
    
}
