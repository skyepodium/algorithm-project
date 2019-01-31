#include <vector>
#include <algorithm>

using namespace std;

int a[10000001];
int solution(vector<int> d, int budget) {

    int answer = 0;
    sort(d.begin(), d.end());
    for(int i=0; i<(int)d.size(); i++){
        if(budget - d[i] >= 0){
            budget -= d[i];
            answer++;
        }
    }
    return answer;
}