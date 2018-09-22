#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int size = (int)s.size();
    if(size != 4 && size != 6){
        answer = false;
    }
    
    for(int i=0; i<size; i++){
        if(s[i] - '0' < 0 || s[i] - '0' >9){
            answer = false;
            break;
        }
    }
    
    return answer;
}
