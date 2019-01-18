#include <string>
#include <vector>

using namespace std;

int answer = 0;
void go(int idx, int sum, vector<int> &v, int target){
    if(idx == (int)v.size()){
        if(sum == target){
            answer++;
        }
        return;
    }

    go(idx + 1, sum + v[idx], v, target);
    go(idx + 1, sum - v[idx], v, target);
}

int solution(vector<int> numbers, int target) {
    go(0, 0, numbers, target);
    return answer;
}