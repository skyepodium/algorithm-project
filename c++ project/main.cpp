#include <string>
#define max_int 4
using namespace std;

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
    int answer = 0;
    int idx = 0, a[max_int] = {0, 0, 0, 0};
    int size = (int)dartResult.size();

    for(int i=0; i < size; i++){
        char cur = dartResult[i];

        if(cur == 'S' || cur == 'D' || cur == 'T'){
            a[idx] = pow(a[idx], cur);
        }
        else if(cur == '*'){
            int start_idx = idx == 1 ? 1 : idx - 1;

            for(int i=start_idx; i<=idx; i++){
                a[i] = a[i] * 2;
            }
        }
        else if(cur == '#'){
            a[idx] = a[idx] * -1;
        }
        else{
            int num = cur - '0';
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

    for(int i=1; i<=3; i++) {
        answer += a[i];
    }

    return answer;
}