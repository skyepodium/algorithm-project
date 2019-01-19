#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double total = 0;
    for(int i=0; i<(int)arr.size(); i++){
        total += arr[i];
    }
    answer = total/(int)arr.size();
    return answer;
}