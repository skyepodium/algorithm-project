#include <iostream>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(1)
//사용한 알고리즘: for문
//사용한 자료구조: 없음


int num;
int result;
int v;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        v = 0;
        result = 0;
        cin >> num;
        
        //반목문을 돌면서 command를 수행한다.
        for(int i=0; i<num; i++){
            int a, b;
            cin >> a;

            if(a != 0){
                cin >> b;
                if(a==1) v = v+b;
                else {
                    v = v-b;
                    //속도는 0밑으로 내려가지 않는다.
                    if(v<0) v = 0;
                }
            }
            
            //command마다 이동거리 갱신
            result = result + v;
        }
        
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}
