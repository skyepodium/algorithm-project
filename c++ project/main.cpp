#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    string number;
    cin >> number;
    
    int size = (int)number.size();
    vector<int> v;
    for(int i=0; i<size; i++){
        v.push_back(number[i]-48);
    }

    vector<int> result;
    int mid_sum = 0;
    int mul_num = 1;
    int cnt = 0;
    
    for(int i=size-1; i>=0; i--){
        if(cnt == 3){
            result.push_back(mid_sum);
            mul_num = 1;
            mid_sum = 0;
            cnt = 0;
        }
        mid_sum = mid_sum + v[i]*mul_num;
        mul_num = mul_num*2;
        cnt++;
    }
    result.push_back(mid_sum);
    
    int result_size = (int)result.size();
    for(int i = result_size-1; i >= 0; i--){
        cout << result[i];
    }
}
