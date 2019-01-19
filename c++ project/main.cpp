#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;

    int num = 0;
    int base = x;
    while(x > 0){
        num += x%10;
        x /= 10;
    }
    if(base%num != 0) answer = false;
    return answer;
}