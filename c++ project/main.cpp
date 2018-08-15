#include <iostream>

using namespace std;

//시간 복잡도: O(n^3)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 3중 for문
//사용한 자료구조: 2차원 배열

//퍼즐의 정보를 저장할 2차원 배열
int d[16][16];

//퍼즐의 크기와 단어의 크기를 저장할 변수
int n, word_size;

//들어갈 수 있는 자리를 저장할 변수
int result;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        //변수 초기화
        result = 0;
        
        cin >> n >> word_size;
        
        //2중for문으로 퍼즐의 정보를 저장한다.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> d[i][j];
            }
        }
       
        //가로 검색
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] == 1){
                    
                    bool check = true;

                    //1. 갯수만큼 1이 있는 지 검사
                    for(int k=j; k<word_size+j; k++){
                        if(k<n){
                            if(d[i][k] == 0){
                                check = false;
                            }
                        }else{
                            check = false;
                        }
                    }
                    
                    //2. 바로 앞에 1이 또 있는지 검사
                    if(j-1 >=0 && d[i][j-1] == 1) check = false;

                    //3. 바로 뒤에 1이 또 있는 지 검사
                    if(j+word_size <= n && d[i][j+word_size] == 1) check = false;
                    
                    //검사를 다 통과했다면 갯수를 1 증가시킨다.
                    if(check == true){
                        result++;
                    }
                }
            }
        }
        
        //세로 검색
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if(d[i][j] == 1){
                    
                    bool check = true;
                    
                    //1. 갯수만큼 1이 있는 지 검사
                    for(int k=i; k<word_size+i; k++){
                        if(k<n){
                            if(d[k][j] == 0){
                                check = false;
                            }
                        }else{
                            check = false;
                        }
                    }
                    
                    //2. 바로 앞에 1이 또 있는지 검사
                    if(i-1 >= 0 && d[i-1][j] == 1) check = false;
                    
                    //3. 바로 뒤에 1이 또 있는 지 검사
                    if(i+word_size <= n && d[i+word_size][j] == 1) check = false;
                    
                    //검사를 다 통과했다면 갯수를 1 증가시킨다.
                    if(check == true){
                        result++;
                    }
                }
            }
        }
        
        cout << "#" << test_case << " " << result << endl;
        
        
    }
    return 0;
}
