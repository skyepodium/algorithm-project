#include <iostream>

using namespace std;

//시간 복잡도: O(logn)
//공간 복잡도: O(n)
//사용한 알고리즘: 반복문
//사용한 자료구조: 1차원 배열

int d[5] = {2, 3, 5, 7, 11};
int result[5];
int num;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //배열 초기화
        for(int i=0; i<5; i++) result[i] = 0;
        
        cin >> num;
        
        //반복문으로 배열을 돌면서 주어진 수를 소인수분해한다.
        for(int i=0; i<5; i++){
            int count = 0;
            while(num%d[i] == 0){
                num = num/d[i];
                count++;
            }
            result[i] = count;
        }
        
        //출력
        cout << "#" << test_case << " ";
        for(int i=0; i<5; i++){
            cout << result [i] << " ";
        }
        cout << endl;
    }
    return 0;
}
