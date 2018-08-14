#include <iostream>
#include <vector>

using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: 선형 탐색
//사용한 자료구조: 1차원 배열

int max_val = 0;
int result = 0;
int d[101];

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //테스트케이스 번호 입력
        int test_case_num;
        cin >> test_case_num;
        
        //초기화
        max_val = 0;
        result = 0;
        for(int i=0; i<101; i++) d[i] = 0;

        //1000명의 점수를 입력받고, 최빈수++
        for(int i=0; i<1000; i++){
            int num;
            cin >> num;
            d[num]++;
        }
        
        //100개의 배열 선형탐색, 최빈수 찾는다.
        for(int i=0; i<101; i++){
            if(d[i] > max_val){
                max_val = d[i];
                result = i;

            }else if(d[i] == max_val){
                if(result < i) result = i;
                
            }
        }
        
        //결과출력
        cout << "#" << test_case << " " << result << endl;
        
    }
    return 0;
}
