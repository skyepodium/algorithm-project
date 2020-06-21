#include <iostream>
#include <string>
#include <vector>
#define min_int 6565
#define max_int 9090
#define base_num 65536
using namespace std; 

/*
    시간 복잡도: O(n)
    공간 복잡도: O(n)
    사용한 알고리즘: 반복문
    사용한 자료구조: 배열
 */

int check[2][max_int + 1];
double duple_cnt=0, total_cnt=0, jaccard=0;

int min(int a, int b){
    return a < b ? a: b;
}

int max(int a, int b){
    return a > b ? a : b;
}

// 영문자 여부를 검사하는 함수
bool is_character(char ch){
    
    bool result = false;
    
    // 대문자 아스키 코드 범위 65~90
    // 소문자 아스키 코드 범위 97~122
    if((ch >= 65 && ch <=90) || (ch>=97 && ch<=122)) result = true;
    
    return result;
}

// 대문자로 바꿔주는 함수
char to_uppercase(char ch){
    char result = 'a';
    
    // 만약 소문자라면 32를 빼서 대문자로 만들어줍니다.
    if(ch >= 97) result = ch - 32;
    else result = ch;

    return result;
}

int solution(string str1, string str2) {
    int answer = 0;

    // 1. 문자열 2개를 배열에 넣는다.
    vector<string> v;
    v.push_back(str1);
    v.push_back(str2);
    
    // 2. 문자열 배열을 순회합니다.
    for(int i=0; i<(int)v.size(); i++){
        
        string word = v[i];
        
        for(int j=0; j<(int)word.size() - 1; j++){
            
            // 1) 문자를 2개씩 검사합니다.
            char first_ch = word[j];
            char second_ch = word[j+1];
            
            // 2) 만약 2개의 문자가 모두 영문자일 경우
            if(is_character(first_ch) && is_character(second_ch)){
                
                // 3) 영문자를 모두 대문자로 만들어줍니다.
                first_ch = to_uppercase(first_ch);
                second_ch = to_uppercase(second_ch);

                // 4) 첫번째 문자에 100을 곱하고 두번째 문자랑 더해서 유니크한 숫자를 만들어줍니다.
                // 대문자의 아스키코드 범위는 65 ~ 90
                // 예) AB -> 6566
                int num = first_ch * 100 + second_ch;
                
                // 유니크한 숫자의 개수를 1증가시켜줍니다.
                check[i][num]++;
            }
        }
    }
    
    /*
        3. 전체 문자를 검사합니다.
        숫자의 최소값은 6565 -> AA
        숫자의 최대값은 9090 -> ZZ
        즉, AA에서 ZZ까지 검사합니다.
     */
    for(int i=min_int; i<=max_int; i++){
        // 1) 합집합은 각 숫자의 최대개수
        total_cnt += max(check[0][i], check[1][i]);
        
        // 2) 교집합은 각 숫자의 최소개수
        duple_cnt += min(check[0][i], check[1][i]);
    }
    
    // 4. 자카드 유사도를 계산합니다.
    // 두 집합이 모두 공집합인 경우 total_cnt == 0 입니다.
    
    // 1) 두 집합이 모두 공집합이 아닌 경우
    if(total_cnt != 0){
        // 실수 계산을 하고
        jaccard = duple_cnt / total_cnt;
        answer = (int)(base_num * jaccard);
    }
    // 2) 두 집합이 모두 공집합인 경우
    else{
        // 규칙에 따라 656636을 넣어줍니다.
        answer = base_num;
    }
    
    return answer;
}

int main(){
    cout << solution("FRANCE", "french") << endl;
}
