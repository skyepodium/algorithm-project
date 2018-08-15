#include <iostream>
#include <string>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n)
//사용한 알고리즘: 2중 반복문
//사용한 자료구조: string


int result;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        result = 0;
        
        //문자열 입력받는다.
        string word1;
        cin >> word1;
        
        int count = 1;
        
        //문자열을 찾았는지 알려주는 변수
        bool find_complete = false;

        while(find_complete == false){

            //count의 크기만큼 문자열을 생성한다.
            string temp;
            for(int i=0; i<count; i++){
                temp = temp + word1[i];
            }
            
            //새로 생성한 문자열을 반복하여 word2를 생성한다.
            int num = 30/count;
            int num_remain = 30%count;
        
            string word2;
            for(int i=0; i<num; i++){
                word2 = word2 + temp;
            }
            for(int i=0; i<num_remain; i++){
                word2 = word2 + temp[i];
            }
        
            //word1, word2 두 문자열이 같은지를 검사한다.
            bool is_find = true;
            for(int i=0; i<30; i++){
                if(word1[i] != word2[i]){
                    is_find = false;
                    break;
                }
            }
        
            //두 문자열이 같으면 반복문을 종료한다.
            if(is_find == true){
                result = count;
                find_complete = true;
            }
        
            count++;
        }
        cout <<"#" << test_case << " " << result << endl;
    }
    return 0;
}
