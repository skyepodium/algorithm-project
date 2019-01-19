#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long int cur = 0;
    for(int i=0; i<n; i++){
        answer.push_back(cur + x);
        cur = cur + x;
    }
    return answer;
}