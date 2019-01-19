#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = (int)phone_number.size();
    int idx = size - 4;
    for(int i=0; i<size; i++){
        if(i < idx) answer += '*';
        else answer += phone_number[i];
    }
    return answer;
}