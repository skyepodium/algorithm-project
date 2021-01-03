#include <string>
#include <vector>
#include <algorithm>
#define max_int 201
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    bool check[max_int];
    for(int i=0; i<max_int; i++) check[i] = false;
    
    for(int i=0; i<numbers.size(); i++) {
        for(int j=0; j<numbers.size(); j++) {
            if(i == j) continue;
            
            int sum_value = numbers[i] + numbers[j];
            
            if(!check[sum_value]) {
                check[sum_value] = true;
                answer.push_back(sum_value);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
