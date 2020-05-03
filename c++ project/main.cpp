#include <string>
#define max_int 4
using namespace std;

/*
    시간 복잡도: O(n)
    공간 복잡도: O(n)
    사용한 알고리즘: 거듭제곱
    사용한 자료구조: 배열
 */

/*
   거듭 제곱
   3제곱 까지 이기 때문에
   num * num * num 해도 되고
   반복문 써도 되고
   분할해서 DP 써도 되고
 */
int pow(int num, char c){
    int result = num;
    int a = 0;
    if(c == 'S') a = 1;
    else if(c == 'D') a = 2;
    else a = 3;

    for(int i=2; i<=a; i++) {
        result = result * num;
    }

    return result;
}

int solution(string dartResult) {
    // 1. 입력 및 초기화
    int answer = 0;
    int idx = 0, a[max_int] = {0, 0, 0, 0};
    int size = (int)dartResult.size();

    // 2. 로직 수행
    for(int i=0; i < size; i++){
        char cur = dartResult[i];

        // 1) 거듭 제곱 진행합니다.
        if(cur == 'S' || cur == 'D' || cur == 'T'){
            a[idx] = pow(a[idx], cur);
        }
        // 2) 2배를 해줍니다.
        else if(cur == '*'){
            /*
                첫번째 게임인 경우 - 현재 점수 * 2
                두번째, 세번째 게임인 경우 - 현재와 바로 전 점수 * 2
             */
            int start_idx = idx == 1 ? 1 : idx - 1;

            for(int i=start_idx; i<=idx; i++){
                a[i] = a[i] * 2;
            }
        }
        // 3) 현재 점수를 -1배 합니다.
        else if(cur == '#'){
            a[idx] = a[idx] * -1;
        }
        // 4) 현재 숫자를 검사합니다.
        else{
            // 아스키코드에서 숫자를 추출합니다.
            int num = cur - '0';

            // 만약 10인경우 (길이 2인 문자열)
            if(cur == '1'){
                if(i < size - 1 && dartResult[i + 1] == '0') {
                    num = 10;
                }
            }

            idx++;
            a[idx] =  num;
            if(num == 10) i += 1;
        }
    }

    // 3. 결과 합산
    for(int i=1; i<=3; i++) {
        answer += a[i];
    }

    // 4. 출력
    return answer;
}