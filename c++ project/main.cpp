#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 2중 for문
//사용한 자료구조: 1차원 배열, 1차원 벡터

//두개의 숫자열을 저장할 배열 2개 생성
int a1[20];
int a2[20];

//계산의 최대값을 저장할 변수 result
int result;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //정수 최소값으로 매번 초기화 시켜준다.
        result = -2147483647;
        int a, b;
        cin >> a >> b;
        
        //첫번째 숫자열을 입력받는다.
        for(int i=0; i<a; i++){
            cin >> a1[i];
        }
        
        //두번째 숫자열을 입력받는다.
        for(int i=0; i<b; i++){
            cin >> a2[i];
        }
        
        //반복문의 횟수 계산
        int loop_order = b-a;
        
        //짧은 숫자열을 저장할 벡터v1, 긴 숫자열을 저장할 벡터v2
        vector<int> v1;
        vector<int> v2;
        
        //만약 첫번째로 주어진 숫자열의 길이가 두번째 보다 크다면
        if(a>b){
            loop_order = a-b;
            
            for(int i=0; i<b; i++){
                v1.push_back(a2[i]);
            }
            
            for(int i=0; i<a; i++){
                v2.push_back(a1[i]);
            }
            
            //a,b 스왑
            int c;
            c = a;
            a = b;
            b = c;
            
        }else{
            for(int i=0; i<a; i++){
                v1.push_back(a1[i]);
            }
            
            for(int i=0; i<b; i++){
                v2.push_back(a2[i]);
            }
        }
        
        //두개의 벡터를 비교하면서 값을 계산한다.
        for(int i=0; i<loop_order+1; i++){
            
            //각 횟수의 계산값을 저장할 변수 total
            int total = 0;
            for(int j=0; j<a; j++){
                total = total + v1[j] * v2[j+i];
            }
            
            //계산의 최대값 갱신
            result = max(result, total);
        }
        
        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}

